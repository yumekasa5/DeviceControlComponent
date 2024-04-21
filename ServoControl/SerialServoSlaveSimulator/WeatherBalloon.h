#ifndef WEATHERBALLOON_H
#define WEATHERBALLOON_H

#include <QPushButton>
#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <QTimer>

class WeatherBalloon : public QPushButton
{
    Q_OBJECT
public:
    WeatherBalloon(QWidget *parent = nullptr);

    double temperture() const;
    double humidity() const;
    double altitude() const;

private slots:
    void sendDiagram();

private:
    QUdpSocket udpSocket;
    QTimer timer;
};

#endif // WEATHERBALLOON_H
