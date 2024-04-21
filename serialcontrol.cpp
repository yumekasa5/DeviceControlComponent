#include "serialcontrol.h"

SerialControl::SerialControl(QObject *parent) :
    QObject{parent},
    mSerial(new QSerialPort(this))
{
    mPortName = "COM3";
    mIsOpen = false;
    //! 接続可能なSerialPort情報をデバッグ表示
    foreach (const QSerialPortInfo info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Name        :" << info.portName();
        qDebug() << "Description :" << info.description();
        qDebug() << "Manufacturer:" << info.manufacturer() << "\n";
    }
    setSerialSettiing();

    //! TODO:
//    QTimer *timer = new QTimer(this);
//    connect(timer, &QTimer::timeout,
//            this, &SerialControl::checkSerialPortStatus);
//    timer->start(500);
}

SerialControl::~SerialControl()
{
    mSerial->close();
}

bool SerialControl::openSerialPort()
{
    bool ret = true;
    if(mSerial->open(QIODevice::ReadWrite)){
        return ret;
    }
    else{
        ret = false;
        return ret;
    }
}

bool SerialControl::closeSerialPort()
{
    bool ret = false;
    if (mSerial->isOpen()) {
        mSerial->close();
        if (mSerial->isOpen()) {
            return ret;
        } else {
            ret = true;
            return ret;
        }
    } else {
        return ret;
    }
}

void SerialControl::setSerialSettiing()
{
    //! SerialPortの設定
    mSerial->setPortName(mPortName);
    mSerial->setBaudRate(mBaudRate);
    mSerial->setDataBits(QSerialPort::Data8);
    mSerial->setParity(QSerialPort::NoParity);
    mSerial->setStopBits(QSerialPort::OneStop);
    mSerial->setFlowControl(QSerialPort::NoFlowControl);
}

bool SerialControl::SerialWrite(QString msg)
{
    mSendData = "Hello, Serial";
    mSerial->write(mSendData);
    qDebug() << "Sent data:" << mSendData;
    return true;
}

void SerialControl::readSerialData(QString &data)
{
    if (sender() == mSerial){
        data = QString(mSerial->readAll());
    }
}

void SerialControl::readyRead()
{
    mSerial->readyRead();
}

bool SerialControl::SerialCheck()
{
    bool ret = false;
    mSerial->write("CHECK");
    return ret;
}

void SerialControl::checkSerialPortStatus()
{
    if(mSerial->isOpen()){
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
