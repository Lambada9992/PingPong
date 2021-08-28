package com.pingpong_controller;

import java.io.*;
import java.net.Socket;
import java.util.concurrent.LinkedBlockingQueue;

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

    public void write(String message){
        try {
            out.put(message);
        } catch (InterruptedException e) {
            //e.printStackTrace();
        }
    }

    public void close(){
        synchronized (this) {
            this.notify();
        }
    }

    public Status getStatus() {
        return status;
    }

    public Socket getSocket(){
        return this.socket;
    }
}
