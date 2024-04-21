#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QtNetwork/QUdpSocket>

class WeatherStation : public QDialog
{
    Q_OBJECT

public:
    WeatherStation(QWidget *parent = nullptr);
    ~WeatherStation();

private slots:
    void processPendingDiagrams();

private:
    QUdpSocket udpSocket;

    QLineEdit *dateLineEdit;
    QLineEdit *timeLineEdit;
    QLineEdit *tempertureLineEdit;
    QLineEdit *humidityLineEdit;
    QLineEdit *altitudeLineEdit;
};
#endif // WEATHERSTATION_H
