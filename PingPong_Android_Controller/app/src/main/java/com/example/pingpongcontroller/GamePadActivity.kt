package com.example.pingpongcontroller

import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.MotionEvent
import android.view.View
import android.widget.Button
import androidx.appcompat.widget.SwitchCompat

class GamePadActivity : AppCompatActivity() {

    lateinit var sSide: SwitchCompat
    lateinit var bDown: Button
    lateinit var bUp: Button

    @SuppressLint("ClickableViewAccessibility")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_game_pad)

        sSide = findViewById(R.id.sSide)
        bDown = findViewById(R.id.bDown)
        bUp = findViewById(R.id.bUp)
        bDown.setOnTouchListener(leftOnTouch)
        bUp.setOnTouchListener(rightOnTouch)
    }

    override fun onDestroy() {
        super.onDestroy()
        PingPongController.disconnect();
    }

    @SuppressLint("ClickableViewAccessibility")
    val leftOnTouch: View.OnTouchListener = View.OnTouchListener { _, event ->
        if(event.action == MotionEvent.ACTION_DOWN) {
            PingPongController.makeMove(getSide(),PingPongController.Move.DOWN,true)
        } else if (event.action == MotionEvent.ACTION_UP) {
            PingPongController.makeMove(getSide(),PingPongController.Move.DOWN,false)
        }
        false
    }

    @SuppressLint("ClickableViewAccessibility")
    val rightOnTouch: View.OnTouchListener = View.OnTouchListener { _, event ->
        if(event.action == MotionEvent.ACTION_DOWN) {
            PingPongController.makeMove(getSide(),PingPongController.Move.UP,true)
        } else if (event.action == MotionEvent.ACTION_UP) {
            PingPongController.makeMove(getSide(),PingPongController.Move.UP,false)
        }
        false
    }

    fun getSide(): PingPongController.Side {
        return when(sSide.isChecked){
            true -> PingPongController.Side.RIGHT
            false -> PingPongController.Side.LEFT
        }
    }

}