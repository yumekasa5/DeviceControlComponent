#ifndef WATCHDOGSERIAL_H
#define WATCHDOGSERIAL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QTimer>

class WatchdogSerial : public QObject
{
    Q_OBJECT
public:
    explicit WatchdogSerial(QObject *parent = nullptr);

public slots:
    void checkSerialPortStatus();

private:
    QSerialPort mSerialPort;
    bool mIsOpen = false;

};

#endif // WATCHDOGSERIAL_H
