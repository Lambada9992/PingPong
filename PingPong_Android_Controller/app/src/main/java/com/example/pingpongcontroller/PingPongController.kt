package com.example.pingpongcontroller

import java.util.regex.Pattern

import java.lang.Exception
import java.io.IOException
import java.lang.IllegalArgumentException
import java.net.ConnectException
import java.net.Socket

/**
 * Singleton odpowiedzialny za całą logikę aplikacji
 */
object PingPongController : ConnectionHandler.ConnectionHandleInterpreter {

    var connectionHandler: ConnectionHandler? = null

    enum class Move{DOWN,UP,NONE}
    enum class Side{LEFT,RIGHT}
    var down = false
    var up = false
    var lastMove = Move.NONE

    private val IPV4_REGEX = "^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
            "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
            "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
            "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$"
    private val IPV4_PATTERN: Pattern = Pattern.compile(IPV4_REGEX)

    /**
     * Metoda odpowiedzialna za wysłanie informacji o wystrzale przez daną paletkę z wykorzystaniem socketu TCP
     */
    fun shot(side: Side){
        var message: String = ""

        message += when(side){
            Side.LEFT -> "L"
            Side.RIGHT -> "R"
        }

        message += "SHOT"

        connectionHandler?.write(message)
    }

    /**
     * Metoda odpowiedzialna za przesłanie informacji przez socket TCP o ruchu użytkownika
     */
    fun makeMove(side: Side,move: Move,press: Boolean){
        var message: String = ""

        message += when(side){
            Side.LEFT -> "L"
            Side.RIGHT -> "R"
        }

        when(move){
            Move.DOWN -> down = press
            Move.UP -> up = press
            else -> throw IllegalArgumentException("NONE can't be pressed or released.")
        }

        when{
            down == up -> {
                if (lastMove != Move.NONE) {
                    message += "NONE"
                    lastMove = Move.NONE
                }
            }
            down && !up -> {
                if(lastMove != Move.DOWN) {
                    message += "DOWN"
                    lastMove = Move.DOWN
                }
            }
            !down && up -> {
                if(lastMove != Move.UP) {
                    message += "UP"
                    lastMove = Move.UP
                }
            }
        }

        connectionHandler?.write(message)
    }

    /**
     * Metoda odpowiedzialna za interpretację przychodzącej wiadomości
     */
    override fun interpretIncomingMessage(message: String?) {

    }

    /**
     * Metoda odpowiedzialna za nawiązanie połączenia TCP
     * @param ip Ip na które ma zostać wykonana próba połączenia
     * @param port Port na który ma zostać wykonana próba połączenia
     */
    fun connect(ip: String,port: Int) {
        if (!IPV4_PATTERN.matcher(ip).matches()) throw Exception("Invalid IP")

        connectionHandler?.run{ disconnect() }

        Thread {
            try {
                val socket = Socket(ip, port)
                connectionHandler = ConnectionHandler(socket, this)
                connectionHandler!!.start()
            } catch (e: ConnectException) {
                e.printStackTrace()
            } catch (e: IOException) {
                e.printStackTrace()
            }
        }.start()
    }

    /**
     * metoda odpowiedzialna za rozłączenie połączenia TCP
     */
    fun disconnect() {
        this.connectionHandler = connectionHandler?.run{
            close()
            null
        }
    }

}