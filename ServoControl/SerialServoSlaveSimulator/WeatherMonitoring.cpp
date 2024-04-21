#include "WeatherMonitoring.h"
#include "ui_WeatherMonitoring.h"

WeatherMonitoring::WeatherMonitoring(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WeatherMonitoring)
{
    ui->setupUi(this);
}

WeatherMonitoring::~WeatherMonitoring()
{
    delete ui;
}

