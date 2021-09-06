package com.example.pingpongcontroller;

import java.io.*;
import java.net.Socket;
import java.util.concurrent.LinkedBlockingQueue;

/**
 * Klasa odpowiedzialna za obsługę socketuTCP/połączenia internetowego
 * Tworzy 3 wątki:
 * Jeden do zarzącania connection handlerem oraz pozostałymi wątkami
 * Jeden wątek do obsługi odczytu przychodzących infromacji
 * Jeden wątek do obsługi wysyłanych informacji
 */
public class ConnectionHandler extends Thread{

    public enum Status{CONNECTED,DISCONNECTED}

    public interface ConnectionHandleInterpreter{
        void interpretIncomingMessage(String message);
    }

    private final Socket socket;
    private ConnectionHandleInterpreter interpreter;
    private Status status = Status.DISCONNECTED;
    private final LinkedBlockingQueue<String> out = new LinkedBlockingQueue<String>();
    private BufferedReader inBuffer;
    private BufferedWriter outBuffer;
    Thread writerThread;
    Thread readerThread;

    /**
     * Implementacja intrrfejsu Runnable wykorzystywanego do przekazania metody jaka ma być wykonywana przez nowy wątek w tym wypadku czyania przychodzących wiadomości
     */
    private final Runnable reader = ()->{
        while (!Thread.currentThread().isInterrupted()){
            try {
                String message = inBuffer.readLine().trim();
                interpreter.interpretIncomingMessage(message);
            } catch (IOException | NullPointerException e) {
                break;
            }
        }
        this.close();
    };
    /**
     * Implementacja intrrfejsu Runnable wykorzystywanego do przekazania metody jaka ma być wykonywana przez nowy wątek w tym wypadku wysyłania wiadomości z outBuffera
     */
    private final Runnable writer = ()->{
        while (!Thread.currentThread().isInterrupted()){
            try {
                String message = out.take();
                outBuffer.write(message+"\r\n");
                outBuffer.flush();
            } catch (IOException e) {
                e.printStackTrace();
            } catch (InterruptedException | NullPointerException e) {
                break;
            }
        }
        this.close();
    };

    /**
     * Konstruktor
     * @param socket socket
     * @param interpreter Interfejs zawieracjący implementację metody odpowiedzialnej za interpretacje przychodzących wiadomości
     */
    public ConnectionHandler(Socket socket, ConnectionHandleInterpreter interpreter) {
        this.socket = socket;
        this.interpreter = interpreter;
        try {
            inBuffer = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            outBuffer = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Metoda odpowiedzialna za działanie głównego wątka zarządzającego pozostałymi
     */
    @Override
    public void run() {
        try {
            status = Status.CONNECTED;
            writerThread = new Thread(writer);
            readerThread = new Thread(reader);
            writerThread.start();
            readerThread.start();

            //Waits to close connection handler
            synchronized (this) {
                this.wait();
            }

            writerThread.interrupt();
            readerThread.interrupt();

        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            status = Status.DISCONNECTED;
            try {
                outBuffer.close();
                socket.close();
                inBuffer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                readerThread.join();
                writerThread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    /**
     * Metoda odpowiedzialna za umieszczenie wiadomości w bufferze które nastepnie sa wysyłąne po przez socket
     * @param message
     */
    public void write(String message){
        try {
            out.put(message);
        } catch (InterruptedException e) {
            //e.printStackTrace();
        }
    }

    /**
     * metoda służąca do zamknięcia całego connection Handlera
     */
    public void close(){
        synchronized (this) {
            this.notify();
        }
    }

}
