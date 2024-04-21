#ifndef WEATHERMONITORING_H
#define WEATHERMONITORING_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class WeatherMonitoring; }
QT_END_NAMESPACE

class WeatherMonitoring : public QWidget
{
    Q_OBJECT

public:
    WeatherMonitoring(QWidget *parent = nullptr);
    ~WeatherMonitoring();

private:
    Ui::WeatherMonitoring *ui;
};
#endif // WEATHERMONITORING_H
