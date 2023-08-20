#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialcontrol.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ランプの背景色設定
    ui->portStateLamp->setStyleSheet("background-color : red;");

    // シグナル・スロット接続
    connect(ui->openButton, &QPushButton::clicked,
            this, &MainWindow::openSerial);
    connect(ui->closeButton, &QPushButton::clicked,
            this, &MainWindow::closeSerial);
    connect(ui->receiveButton, &QPushButton::clicked,
            this, &MainWindow::receiveData);
    connect(ui->checkButton, &QPushButton::clicked,
            this, &MainWindow::checkSerial);
    connect(&mSerialControl, &SerialControl::SIGNAL_checkSerialPortStatus,
            this, &MainWindow::changeStatusColor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveDebug()
{
    qDebug() << Q_FUNC_INFO;
}

void MainWindow::openSerial()
{
    mSerialControl.SerialOpen();
}

void MainWindow::closeSerial()
{
    mSerialControl.SerialClose();
}

void MainWindow::receiveData()
{
    mSerialControl.SerialRead();
}

void MainWindow::checkSerial()
{
    mSerialControl.SerialCheck();
}

void MainWindow::changeStatusColor()
{
    if(mSerialControl.getPortStatus()){
        ui->portStateLamp->setStyleSheet("background-color : green;");
    }else{
        ui->portStateLamp->setStyleSheet("background-color : red;");
    }
}

