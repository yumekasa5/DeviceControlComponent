#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>
#include <QPlainTextEdit>
#include <QSerialPort>

#include "serialcontrol.h"
#include "SerialMonitorWidget.h"

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
    void addLog(const QString &logtext);

private slots:
    void receiveData();
    void checkSerial();
    void changeStatusColor();
    void printData();

    void on_openSerialMonitorButton_clicked();
    void openSerialMonitorWidget();

private:
    Ui::MainWindow *ui;

    QSerialPort *mSerialPort;
    SerialControl *mSerialControl;
//    QListView *mLogListView;
//    QStringListModel *mLogModel;
    QPlainTextEdit *mLogPlainTextEdit;
//    SerialMonitorWidget* mSerialMonitor;

    bool mStatus = false;
    QString str_buff = "";


};
#endif // MAINWINDOW_H
