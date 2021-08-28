package com.pingpong_controller

import java.util.regex.Pattern

import java.lang.Exception
import java.io.IOException
import java.net.ConnectException
import java.net.Socket

class PingPongController : ConnectionHandler.ConnectionHandleInterpreter {

    var connectionHandler: ConnectionHandler? = null

    private val IPV4_REGEX = "^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
            "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
            "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
            "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$"
    private val IPV4_PATTERN: Pattern = Pattern.compile(IPV4_REGEX)

    override fun interpretIncomingMessage(message: String?) {
        TODO("Not yet implemented")
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