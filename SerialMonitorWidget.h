#ifndef SERIALMONITORWIDGET_H
#define SERIALMONITORWIDGET_H

#include <QObject>
#include <QWidget>

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
};

#endif // SERIALMONITORWIDGET_H
