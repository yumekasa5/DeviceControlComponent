#include "WeatherBalloon.h"

#include <QDateTime>

WeatherBalloon::WeatherBalloon(QWidget *parent) :
    QPushButton("Quit", parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(close()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(sendDiagram()));

    timer.start(2000);

    setWindowTitle("Weather Balloon");

}

double WeatherBalloon::temperture() const
{
    return 25.0;
}

double WeatherBalloon::humidity() const
{
    return 40.0;
}

double WeatherBalloon::altitude() const
{
    return 150.2;
}

void WeatherBalloon::sendDiagram()
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_15);
    out << QDateTime::currentDateTime() << temperture() << humidity() << altitude();
    udpSocket.writeDatagram(datagram, QHostAddress::LocalHost, 5824);

}
