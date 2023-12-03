#ifndef SERIALMONITORWIDGET_H
#define SERIALMONITORWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include "serialcontrol.h"
#include "SerialManager.h"

namespace Ui {
class SerialMonitorWidget;
}

class SerialMonitorWidget : public QWidget
{
    Q_OBJECT

public:
    SerialMonitorWidget(QWidget *parent = nullptr);
    ~SerialMonitorWidget();

    void printData();


private:
    Ui::SerialMonitorWidget *ui;
    SerialManager *mSerialManager;
    QSerialPort *mSerialPort;
    SerialControl *mSerial;
};

#endif // SERIALMONITORWIDGET_H
