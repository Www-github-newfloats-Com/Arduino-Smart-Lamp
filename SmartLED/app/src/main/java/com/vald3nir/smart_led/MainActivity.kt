package com.vald3nir.smart_led

import android.graphics.Color
import android.os.Bundle
import android.view.View
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import top.defaults.colorpicker.ColorObserver
import top.defaults.colorpicker.ColorPickerView

class MainActivity : AppCompatActivity(), ColorObserver {

    private var redLabel: TextView? = null
    private var greenLabel: TextView? = null
    private var blueLabel: TextView? = null
    private var timeLabel: TextView? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        redLabel = findViewById(R.id.redLabel)
        greenLabel = findViewById(R.id.greenLabel)
        blueLabel = findViewById(R.id.blueLabel)
        timeLabel = findViewById(R.id.timeLabel);

        val colorPickerView = findViewById<ColorPickerView>(R.id.colorPicker)
        colorPickerView.setInitialColor(0x7F313C93);
        colorPickerView.subscribe(this)


    }

    override fun onColor(color: Int, fromUser: Boolean, shouldPropagate: Boolean) {
        redLabel?.text = Color.red(color).toString()
        greenLabel?.text = Color.green(color).toString()
        blueLabel?.text = Color.blue(color).toString()
    }


    fun onApplyColor(view: View) {
        val msg: String = "" + redLabel?.text + "," + greenLabel?.text + "," + blueLabel?.text + "," + timeLabel?.text.toString()
        Toast.makeText(this, msg, Toast.LENGTH_SHORT).show();

    }

}