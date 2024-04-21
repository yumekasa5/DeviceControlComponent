#include "SerialMonitorWidget.h"
#include "ui_SerialMonitorWidget.h"

SerialMonitorWidget::SerialMonitorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialMonitorWidget)
{
    ui->setupUi(this);
}

SerialMonitorWidget::~SerialMonitorWidget()
{
    delete ui;
}

void SerialMonitorWidget::printData()
{

}
