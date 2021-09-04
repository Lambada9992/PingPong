package com.example.pingpongcontroller

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.EditText

class MainActivity : AppCompatActivity() {


    lateinit var etIp: EditText
    private lateinit var bConnection: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)


        etIp = findViewById(R.id.etIpAddress)
        bConnection = findViewById(R.id.bConnection)


        bConnection.setOnClickListener(connectOnClick)
    }



    private val connectOnClick: View.OnClickListener = View.OnClickListener {
        val ipAddress = etIp.text.toString()
        PingPongController.connect(ipAddress,1234)
        startActivity(Intent(this,GamePadActivity::class.java))
    }

}