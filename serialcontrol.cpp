#include "serialcontrol.h"

SerialControl::SerialControl(QObject *parent)
    : QObject{parent}
{
    mSerial.setPortName(mPortName);
    mSerial.setBaudRate(QSerialPort::Baud115200);
    mSerial.setDataBits(QSerialPort::Data8);
    mSerial.setParity(QSerialPort::NoParity);
    mSerial.setStopBits(QSerialPort::OneStop);
    mSerial.setFlowControl(QSerialPort::NoFlowControl);
    mBaudRate = mSerial.baudRate();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout,
            this, &SerialControl::checkSerialPortStatus);
    timer->start(500);
}

bool SerialControl::SerialOpen()
{
    bool ret = false;
    if(!mSerial.open(QIODevice::ReadWrite)){
        return ret;
    }
    else{
        ret = true;
    }
    return ret;
}

bool SerialControl::SerialClose()
{
    bool ret = false;
    if (mSerial.isOpen()) {
        mSerial.close();
        if (mSerial.isOpen()) {
            return ret;
        } else {
            ret = true;
            return ret;
        }
    } else {
        return ret;
    }
}

bool SerialControl::SerialWrite(QString msg)
{
    mSendData = "Hello, Serial";
    mSerial.write(mSendData);
    qDebug() << "Sent data:" << mSendData;
    return true;
}

bool SerialControl::SerialRead(QString &revdata)
{
//    bool ret = false;
    mReceivedData = mSerial.readAll();
    mReceivedDataString = QString::fromUtf8(mReceivedData).trimmed();
    qDebug() << "Received data:" << mReceivedDataString;
    revdata = mReceivedDataString;
    return true;
}

bool SerialControl::SerialCheck()
{
    bool ret = false;
    mSerial.write("CHECK");
    return ret;
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

qint32 SerialControl::getBaudRate()
{
    return mBaudRate;
}

QString SerialControl::getPortName()
{
    return mPortName;
}
