package com.example.pingpongcontroller

import java.util.regex.Pattern

import java.lang.Exception
import java.io.IOException
import java.lang.IllegalArgumentException
import java.net.ConnectException
import java.net.Socket

class PingPongController : ConnectionHandler.ConnectionHandleInterpreter {

    var connectionHandler: ConnectionHandler? = null

    enum class Move{LEFT,RIGHT,NONE}
    var left = false
    var right = false
    var lastMove = Move.NONE

    private val IPV4_REGEX = "^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
            "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
            "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
            "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$"
    private val IPV4_PATTERN: Pattern = Pattern.compile(IPV4_REGEX)

    fun makeMove(move: Move,press: Boolean){
        when(move){
            Move.LEFT -> left = press
            Move.RIGHT -> right = press
            else -> throw IllegalArgumentException("NONE can't be pressed or released.")
        }
        when{
            left == right -> {
                if (lastMove != Move.NONE) {
                    connectionHandler?.write("NONE")
                    lastMove = Move.NONE
                }
            }
            left && !right -> {
                if(lastMove != Move.LEFT) {
                    connectionHandler?.write("LEFT")
                    lastMove = Move.LEFT
                }
            }
            !left && right -> {
                if(lastMove != Move.RIGHT) {
                    connectionHandler?.write("RIGHT")
                    lastMove = Move.RIGHT
                }
            }
        }
    }

    override fun interpretIncomingMessage(message: String?) {

    }

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

    fun disconnect() {
        this.connectionHandler = connectionHandler?.run{
            close()
            null
        }
    }

}