#include "SerialManager.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

SerialManager::SerialManager(QObject *parent)
    : QObject{parent}
{
//    mSerialPort = QSerialPort();
}

QSerialPort* getSerialPort()
{
        foreach (const QSerialPortInfo info, QSerialPortInfo::availablePorts()) {
            qDebug() << "Name           :" << info.portName();
            qDebug() << "Description    :" << info.description();
            qDebug() << "Manufacturer   :" << info.manufacturer() << "\n";
        }
        return mSerialPort->get();
}

SerialManager::~SerialManager()
{
        mSerialPort->close();
        delete mSerialPort;
}

void SerialManager::Initialize()
{
        mSerialPort->setPortName(QString("COM3"));
        mSerialPort->setBaudRate(QSerialPort::Baud115200);
        mSerialPort->setDataBits(QSerialPort::Data8);
        mSerialPort->setParity(QSerialPort::NoParity);
        mSerialPort->setStopBits(QSerialPort::OneStop);

}
