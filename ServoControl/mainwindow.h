#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "serialcontrol.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void receiveDebug();

private slots:
    void openSerial();
    void closeSerial();
    void receiveData();
    void checkSerial();
    void changeStatusColor();

private:
    Ui::MainWindow *ui;
    SerialControl mSerialControl;
};
#endif // MAINWINDOW_H
