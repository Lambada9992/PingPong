package com.example.pingpongcontroller

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.EditText

/**
 * Logika głównego ekran aplikacji na którym jest możliwość wpisania IP oraz wykonania połączenia
 */
class MainActivity : AppCompatActivity() {

    lateinit var etIp: EditText
    private lateinit var bConnection: Button

    /**
     * Metoda wywoływana przy stworzeniu Activity ala konstruktor
     */
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)


        etIp = findViewById(R.id.etIpAddress)
        bConnection = findViewById(R.id.bConnection)


        bConnection.setOnClickListener(connectOnClick)
    }

    /**
     * Zmienna zawierająca metodę odpowiedzialna za obsłużenie eventu spowodowanego naciśnięciem przycisku Connect na ekranie głównym
     */
    private val connectOnClick: View.OnClickListener = View.OnClickListener {
        val ipAddress = etIp.text.toString()
        try {
            PingPongController.connect(ipAddress,1234)
        }catch (e: Exception){
            return@OnClickListener
        }
        startActivity(Intent(this,GamePadActivity::class.java))
    }

}