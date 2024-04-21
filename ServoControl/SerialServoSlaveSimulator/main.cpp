#include "WeatherMonitoring.h"
#include "WeatherBalloon.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WeatherBalloon balloon;
    balloon.show();
    return a.exec();
}
