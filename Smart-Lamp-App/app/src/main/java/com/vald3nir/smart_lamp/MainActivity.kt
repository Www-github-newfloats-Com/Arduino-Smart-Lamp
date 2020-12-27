package com.vald3nir.smart_lamp

import android.graphics.Color
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*
import top.defaults.colorpicker.ColorObserver

class MainActivity : AppCompatActivity(), ColorObserver {

    private var delegate = MainDelegate()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        initViews()
        delegate.init(this)
    }

    private fun initViews() {
        colorPicker?.setInitialColor(0x7F313C93);
        colorPicker?.subscribe(this)
        btApply?.setOnClickListener {
            delegate.onApplyColor(
                redLabel?.text.toString(),
                greenLabel?.text.toString(),
                blueLabel?.text.toString()
            )
        }
    }

    override fun onColor(color: Int, fromUser: Boolean, shouldPropagate: Boolean) {
        redLabel?.text = Color.red(color).toString()
        greenLabel?.text = Color.green(color).toString()
        blueLabel?.text = Color.blue(color).toString()
    }


}