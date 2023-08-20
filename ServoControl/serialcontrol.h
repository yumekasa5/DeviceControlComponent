#ifndef SERIALCONTROL_H
#define SERIALCONTROL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QTimer>


class SerialControl : public QObject
{
    Q_OBJECT
public:
    explicit SerialControl(QObject *parent = nullptr);
    bool SerialOpen();
    bool SerialClose();
    bool SerialWrite(QString msg);
    bool SerialRead();
    bool SerialCheck();
    void checkSerialPortStatus();
    bool getPortStatus();

signals:
    void SIGNAL_checkSerialPortStatus();

private:
    QSerialPort mSerial;
    QString mPortName = "COM3";
    QByteArray mSendData;
    QByteArray mReceivedData;
    QString mReceivedDataString;
    bool mIsOpen = false;

};

#endif // SERIALCONTROL_H
