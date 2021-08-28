package com.example.pingpongcontroller

import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.MotionEvent
import android.view.View
import android.widget.Button
import android.widget.EditText

class MainActivity : AppCompatActivity() {
    private val pingPongController: PingPongController = PingPongController()

    lateinit var bLeft: Button
    lateinit var bRight: Button
    lateinit var etIp: EditText
    private lateinit var bConnection: Button

    @SuppressLint("ClickableViewAccessibility")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        bLeft = findViewById(R.id.bLeft)
        bRight = findViewById(R.id.bRight)
        etIp = findViewById(R.id.etIpAddress)
        bConnection = findViewById(R.id.bConnection)

        bLeft.setOnTouchListener(leftOnTouch)
        bLeft.setOnTouchListener(rightOnTouch)
        bConnection.setOnClickListener(connectOnClick)
    }

    @SuppressLint("ClickableViewAccessibility")
    val leftOnTouch: View.OnTouchListener = View.OnTouchListener { _, event ->
        if(event.action == MotionEvent.ACTION_DOWN) {
            // TODO
        } else if (event.action == MotionEvent.ACTION_UP) {
            //TODO
        }
        true
    }

    @SuppressLint("ClickableViewAccessibility")
    val rightOnTouch: View.OnTouchListener = View.OnTouchListener { _, event ->
        if(event.action == MotionEvent.ACTION_DOWN) {
            //TODO
        } else if (event.action == MotionEvent.ACTION_UP) {
            //TODO
        }
        true
    }

    private val connectOnClick: View.OnClickListener = View.OnClickListener {
        pingPongController.connect("192.168.0.29",1234)
    }

}