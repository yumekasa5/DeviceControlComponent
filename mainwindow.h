#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>
#include <QPlainTextEdit>

#include "serialcontrol.h"

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
    void openSerial();
    void closeSerial();
    void receiveData();
    void checkSerial();
    void changeStatusColor();

private:
    Ui::MainWindow *ui;
    SerialControl mSerialControl;
//    QListView *mLogListView;
//    QStringListModel *mLogModel;
    QPlainTextEdit *mLogPlainTextEdit;

};
#endif // MAINWINDOW_H
