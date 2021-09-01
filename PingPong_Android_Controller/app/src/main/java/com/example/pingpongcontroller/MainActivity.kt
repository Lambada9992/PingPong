package com.example.pingpongcontroller

import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.MotionEvent
import android.view.View
import android.widget.Button
import android.widget.EditText
import java.util.*

class MainActivity : AppCompatActivity() {
    private val pingPongController: PingPongController = PingPongController()

    lateinit var bLeft: Button
    lateinit var bRight: Button
    lateinit var etIp: EditText
    private lateinit var bConnection: Button

    val IP = "192.168.0.13"

    val connectionStatusObs: Observer = Observer { _, _ ->
        //TODO update connection Status
    }

    @SuppressLint("ClickableViewAccessibility")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        bLeft = findViewById(R.id.bLeft)
        bRight = findViewById(R.id.bRight)
        etIp = findViewById(R.id.etIpAddress)
        bConnection = findViewById(R.id.bConnection)

        bLeft.setOnTouchListener(leftOnTouch)
        bRight.setOnTouchListener(rightOnTouch)
        bConnection.setOnClickListener(connectOnClick)
    }

    @SuppressLint("ClickableViewAccessibility")
    val leftOnTouch: View.OnTouchListener = View.OnTouchListener { _, event ->
        if(event.action == MotionEvent.ACTION_DOWN) {
            pingPongController.makeMove(PingPongController.Move.LEFT,true)
        } else if (event.action == MotionEvent.ACTION_UP) {
            pingPongController.makeMove(PingPongController.Move.LEFT,false)
        }
        false
    }

    @SuppressLint("ClickableViewAccessibility")
    val rightOnTouch: View.OnTouchListener = View.OnTouchListener { _, event ->
        if(event.action == MotionEvent.ACTION_DOWN) {
            pingPongController.makeMove(PingPongController.Move.RIGHT,true)
        } else if (event.action == MotionEvent.ACTION_UP) {
            pingPongController.makeMove(PingPongController.Move.RIGHT,false)
        }
        false
    }

    private val connectOnClick: View.OnClickListener = View.OnClickListener {
        val ipAddress = etIp.text.toString()
        pingPongController.connect(IP,1234)
        //pingPongController.connect(ipAddress,1234) //TODO catch invalid IP
    }

}