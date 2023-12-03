#include "SerialMonitorWidget.h"
#include "ui_SerialMonitorWidget.h"

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

SerialMonitorWidget::SerialMonitorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialMonitorWidget),
    mSerialPort(new QSerialPort(this)),
    mSerial(nullptr)
{
    ui->setupUi(this);
//    mSerialManager = &SerialManager::singleton();
//    mSerialPort = mSerialManager.getSerilaPort();
    if(mSerialPort->open(QIODevice::ReadOnly)){
        connect(mSerialPort, &QSerialPort::readyRead, this, &SerialMonitorWidget::printData);
    }else{
        qDebug() << "Cound't open the port [COM3].";
    }
}

SerialMonitorWidget::~SerialMonitorWidget()
{
    mSerialPort->close();
    disconnect(mSerialPort, &QSerialPort::readyRead, this, &SerialMonitorWidget::printData);
    delete mSerialPort;
    delete ui;
}

void SerialMonitorWidget::printData()
{
    // 現在実行中のslotがQSerialPortオブジェクトであるかどうか
    if(sender() == mSerialPort)
    {
        QString data = QString(mSerialPort->readAll());
        ui->textEdit->append(data);
    }
}
