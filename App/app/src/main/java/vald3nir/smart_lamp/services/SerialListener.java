package vald3nir.smart_lamp.services;

public interface SerialListener {

    void onSerialConnect();

    void onSerialConnectError(Exception e);

    void onSerialRead(byte[] data);

    void onSerialIoError(Exception e);
}
