package com.vald3nir.smart_lamp

import android.app.Activity
import android.util.Log
import org.eclipse.paho.android.service.MqttAndroidClient
import org.eclipse.paho.client.mqttv3.*
import org.json.JSONObject

// doc: https://www.emqx.io/blog/android-connects-mqtt-using-kotlin

class MainDelegate {

    private lateinit var mqttClient: MqttAndroidClient

    companion object {
        const val TAG = "MQTT_TEST_CLIENT"
    }

    fun init(context: Activity) {
        val serverURI = "tcp://broker.mqttdashboard.com:1883"

        mqttClient = MqttAndroidClient(context, serverURI, "kotlin_client")

        mqttClient.setCallback(object : MqttCallback {

            override fun messageArrived(topic: String?, message: MqttMessage?) {
                Log.d(TAG, "Receive message: ${message.toString()} from topic: $topic")
            }

            override fun connectionLost(cause: Throwable?) {
                Log.d(TAG, "Connection lost ${cause.toString()}")
            }

            override fun deliveryComplete(token: IMqttDeliveryToken?) {}
        })

        val options = MqttConnectOptions()

        try {

            mqttClient.connect(options, null, object : IMqttActionListener {

                override fun onSuccess(asyncActionToken: IMqttToken?) {
                    Log.d(TAG, "Connection success")
                }

                override fun onFailure(asyncActionToken: IMqttToken?, exception: Throwable?) {
                    Log.d(TAG, "Connection failure")
                }
            })

        } catch (e: MqttException) {
            e.printStackTrace()
        }
    }

    fun onApplyColor(red: String?, green: String?, blue: String?) {
        val json = JSONObject()
        json.put("r", red)
        json.put("g", green)
        json.put("b", blue)
        publish("smart_lamp", json.toString())
    }

    fun publish(topic: String, msg: String, qos: Int = 0, retained: Boolean = true) {
        try {
            val message = MqttMessage()
            message.payload = msg.toByteArray()
            message.qos = qos
            message.isRetained = retained

            mqttClient.publish(topic, message, null, object : IMqttActionListener {

                override fun onSuccess(asyncActionToken: IMqttToken?) {
                    Log.d(TAG, "$msg published to $topic")
                }

                override fun onFailure(asyncActionToken: IMqttToken?, exception: Throwable?) {
                    Log.d(TAG, "Failed to publish $msg to $topic")
                }
            })

        } catch (e: MqttException) {
            e.printStackTrace()
        }
    }
}