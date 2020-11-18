package vald3nir.smart_lamp.bluetooth.terminal;

interface SerialListener {

    void onSerialConnect();

    void onSerialConnectError(Exception e);

    void onSerialRead(byte[] data);

    void onSerialIoError(Exception e);
}
