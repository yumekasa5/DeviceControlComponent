#include "serialcontrol.h"

SerialControl::SerialControl(QObject *parent)
    : QObject{parent}
{
    mSerial.setPortName(mPortName);
    mSerial.setBaudRate(QSerialPort::Baud9600);
    mSerial.setDataBits(QSerialPort::Data8);
    mSerial.setParity(QSerialPort::NoParity);
    mSerial.setStopBits(QSerialPort::OneStop);
    mSerial.setFlowControl(QSerialPort::NoFlowControl);
    qDebug() << "Create SerialControl class\n";
    qDebug() << mPortName << "\n";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout,
            this, &SerialControl::checkSerialPortStatus);
    timer->start(1000);
}

bool SerialControl::SerialOpen()
{
    bool ret = false;
    if(!mSerial.open(QIODevice::ReadWrite)){
        qDebug() << "Failed to open serial port.";
    }
    else{
        ret = true;
    }
    return ret;
}

bool SerialControl::SerialClose()
{
    bool ret = false;
    mSerial.close();
    ret = true;
    return ret;
}

bool SerialControl::SerialWrite(QString msg)
{
    mSendData = "Hello, Serial";
    mSerial.write(mSendData);
    qDebug() << "Sent data:" << mSendData;
    return true;
}

bool SerialControl::SerialRead()
{
//    bool ret = false;
    mReceivedData = mSerial.readAll();
    mReceivedDataString = QString::fromUtf8(mReceivedData);
    qDebug() << "Received data:" << mReceivedDataString;
    return true;
}

bool SerialControl::SerialCheck()
{
    qDebug() << "Serial Check";
    mSerial.write("CHECK");
    return true;
}

void SerialControl::checkSerialPortStatus()
{
    if(mSerial.isOpen()){
        mIsOpen = true;
    }
    else{
        mIsOpen = false;
    }
    emit SIGNAL_checkSerialPortStatus();
}

bool SerialControl::getPortStatus()
{
    return mIsOpen;
}
