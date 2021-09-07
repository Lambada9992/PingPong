package com.example.pingpongcontroller

import android.annotation.SuppressLint
import android.content.Context
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.MotionEvent
import android.view.View
import android.widget.Button
import androidx.appcompat.widget.SwitchCompat

/**
 * Klasa odpowiedzialna za logikę ekranu kontrolera gry
 */
class GamePadActivity : AppCompatActivity(), SensorEventListener {

    private val TAG = "GamePadActivity"

    lateinit var sSide: SwitchCompat
    lateinit var bDown: Button
    lateinit var bUp: Button
    lateinit var bShot: Button
    lateinit var sRotation: SwitchCompat
    var lastRotation = false

    lateinit var sensorManager: SensorManager
    lateinit var accelerometer: Sensor

    /**
     * Metoda wywoływana przy stworzeniu activity ala konstruktor
     */
    @SuppressLint("ClickableViewAccessibility")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_game_pad)

        sensorManager = getSystemService(Context.SENSOR_SERVICE) as SensorManager
        accelerometer = sensorManager.getDefaultSensor(Sensor.TYPE_GRAVITY)
        sensorManager.registerListener(this, accelerometer, SensorManager.SENSOR_DELAY_NORMAL)

        Log.d(TAG, "CREATE: ")

        sSide = findViewById(R.id.sSide)
        bDown = findViewById(R.id.bDown)
        bUp = findViewById(R.id.bUp)
        bShot = findViewById(R.id.bShot)
        sRotation = findViewById(R.id.sRotation)
        bDown.setOnTouchListener(downOnTouch)
        bUp.setOnTouchListener(upOnTouch)
        bShot.setOnTouchListener(shotOnTouch)
    }

    /**
     * Zmienna zawierająca metodę obsługującą naciśnięcie przycisku DOWN
     */
    @SuppressLint("ClickableViewAccessibility")
    val downOnTouch: View.OnTouchListener = View.OnTouchListener { _, event ->
        if(event.action == MotionEvent.ACTION_DOWN) {
            PingPongController.makeMove(getSide(),PingPongController.Move.DOWN,true)
        } else if (event.action == MotionEvent.ACTION_UP) {
            PingPongController.makeMove(getSide(),PingPongController.Move.DOWN,false)
        }
        false
    }

    /**
     * Zmienna zawierająca metodę obsługującą naciśnięcie przycisku UP
     */
    @SuppressLint("ClickableViewAccessibility")
    val upOnTouch: View.OnTouchListener = View.OnTouchListener { _, event ->
        if(event.action == MotionEvent.ACTION_DOWN) {
            PingPongController.makeMove(getSide(),PingPongController.Move.UP,true)
        } else if (event.action == MotionEvent.ACTION_UP) {
            PingPongController.makeMove(getSide(),PingPongController.Move.UP,false)
        }
        false
    }

    /**
     * Zmienna zawierająca metodę obsługującą naciśnięcie przycisku SHOT
     */
    @SuppressLint("ClickableViewAccessibility")
    val shotOnTouch: View.OnTouchListener = View.OnTouchListener { _, event ->
        if(event.action == MotionEvent.ACTION_DOWN) {
            PingPongController.shot(getSide());
        }
        false
    }

    /**
     * Metoda zwracająca któr strona/paletka jest aktualnie wybrana
     */
    fun getSide(): PingPongController.Side {
        return when(sSide.isChecked){
            true -> PingPongController.Side.RIGHT
            false -> PingPongController.Side.LEFT
        }
    }

    /**
     * Metoda obsługująca zmiany wskazań akcelerometru
     */
    override fun onSensorChanged(event: SensorEvent?) {
        val gx = event?.values?.get(0)?:0.0f
        //Log.d(TAG, "onSensorChanged: ${event?.values?.get(0)?:0.0f}, ${event?.values?.get(1)?:0.0f}, ${event?.values?.get(2)?:0.0f}")

        when{
            lastRotation && !sRotation.isChecked ->{
                PingPongController.makeMove(getSide(),PingPongController.Move.UP,false)
                PingPongController.makeMove(getSide(),PingPongController.Move.DOWN,false)
                lastRotation = false
            }
            !lastRotation && sRotation.isChecked ->{
                lastRotation = true
            }
        }


        if(sRotation.isChecked){
            if( gx > 3.0){
                PingPongController.makeMove(getSide(),PingPongController.Move.UP,true)
                PingPongController.makeMove(getSide(),PingPongController.Move.DOWN,false)
            }else if( gx < -3.0){
                PingPongController.makeMove(getSide(),PingPongController.Move.DOWN,true)
                PingPongController.makeMove(getSide(),PingPongController.Move.UP,false)
            }else{
                PingPongController.makeMove(getSide(),PingPongController.Move.UP,false)
                PingPongController.makeMove(getSide(),PingPongController.Move.DOWN,false)
            }
        }
    }

    override fun onAccuracyChanged(p0: Sensor?, p1: Int) {
       //Do nothing
    }

}