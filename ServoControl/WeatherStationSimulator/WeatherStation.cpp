#include "WeatherStation.h"

#include <QDateTime>

WeatherStation::WeatherStation(QWidget *parent)
    : QDialog(parent)
{
    dateLineEdit = new QLineEdit(this);
    timeLineEdit = new QLineEdit(this);
    tempertureLineEdit = new QLineEdit(this);
    humidityLineEdit = new QLineEdit(this);
    altitudeLineEdit = new QLineEdit(this);
    udpSocket.bind(5824);
    connect(&udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDiagrams()));
}

WeatherStation::~WeatherStation()
{
}

void WeatherStation::processPendingDiagrams()
{
    QByteArray datagram;

    do{
        datagram.resize(udpSocket.pendingDatagramSize());
        udpSocket.readDatagram(datagram.data(), datagram.size());
    }while (udpSocket.hasPendingDatagrams());

    QDateTime dateTime;
    double temperture;
    double humidity;
    double altitude;

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_15);
    in >> dateTime >> temperture >> humidity >> altitude;

    dateLineEdit->setText(dateTime.date().toString());
    timeLineEdit->setText(dateTime.time().toString());
    tempertureLineEdit->setText(QString("%1 cdeg"). arg(temperture));
    humidityLineEdit->setText(QString("%1 %").arg(humidity));
    altitudeLineEdit->setText((QString("%1 m").arg(altitude)));


}

