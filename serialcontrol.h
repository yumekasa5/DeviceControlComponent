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
    bool SerialRead(QString &revdata);
    bool SerialCheck();
    void checkSerialPortStatus();
    bool getPortStatus();
    qint32 getBaudRate();
    QString getPortName();

signals:
    void SIGNAL_checkSerialPortStatus();

private:
    QSerialPort mSerial;
    QString mPortName = "COM3";
    QByteArray mSendData;
    QByteArray mReceivedData;
    QString mReceivedDataString;
    qint32 mBaudRate;
    bool mIsOpen = false;

};

#endif // SERIALCONTROL_H
