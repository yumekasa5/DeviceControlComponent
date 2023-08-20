#include "watchdogserial.h"

WatchdogSerial::WatchdogSerial(QObject *parent)
    : QObject{parent}
{
    mSerialPort.setPortName("COM3");

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout,
            this, &WatchdogSerial::checkSerialPortStatus);
    timer->start(1000);

}

void WatchdogSerial::checkSerialPortStatus()
{
    if(mSerialPort.isOpen()){
        mIsOpen = true;
    }
    else{
        mIsOpen = false;
    }
}
