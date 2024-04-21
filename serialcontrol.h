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
    ~SerialControl();
    bool openSerialPort();
    bool closeSerialPort();
    void setSerialSettiing();
    bool SerialWrite(QString msg);
    void readSerialData(QString &data);

    bool SerialCheck();
    void checkSerialPortStatus();
    bool getPortStatus();
    qint32 getBaudRate();
    QString getPortName();

public slots:
    void readyRead();

signals:
    void SIGNAL_checkSerialPortStatus();

private:
    QSerialPort *mSerial;
    QString mPortName;
    QByteArray mSendData;
    QByteArray mReceivedData;
    QString mReceivedDataString;
    QSerialPort::BaudRate mBaudRate = QSerialPort::Baud115200;
    bool mIsOpen;

};

#endif // SERIALCONTROL_H
