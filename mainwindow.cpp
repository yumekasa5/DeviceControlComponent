#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialcontrol.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // アプリ名とバージョンを取得してQLabelに設定
    QString appName = QCoreApplication::applicationName();
    QString appVersion = QCoreApplication::applicationVersion();
    ui->labelAppNameVersion->setText(appName + " ver. " + appVersion);


    // ランプの背景色設定
    ui->portStateLamp->setStyleSheet("background-color : red;");
    mLogPlainTextEdit = ui->logPlainTextEdit;
    mLogPlainTextEdit->setReadOnly(true);
//    mLogListView = ui->logListView;
//    mLogModel = new QStringListModel(this);
//    mLogListView->setModel(mLogModel);


    this->addLog("Serial Setting");
    this->addLog(QString("Serial Port:%1").arg(mSerialControl.getPortName()));
    this->addLog(QString("Baudrate:%1").arg(QString::number(mSerialControl.getBaudRate())));

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

// デバッグ用受信関数
void MainWindow::receiveDebug()
{
    qDebug() << Q_FUNC_INFO;
}

// LogをGUIに表示
void MainWindow::addLog(const QString &logtext)
{
//    QStringList loglist = mLogModel->stringList();
//    loglist.append(logtext);
//    mLogModel->setStringList(loglist);

//    QModelIndex lastindex = mLogModel->index(loglist.size() - 1, 0);
//    mLogListView->scrollTo(lastindex);
    mLogPlainTextEdit->appendPlainText(logtext);
}

void MainWindow::openSerial()
{
    bool ret = false;
    ret = mSerialControl.SerialOpen();
    if(ret){
        this->addLog("Serial port opened successfully.");
    }else{
        this->addLog("Failed to open serial port.");
    }
}

void MainWindow::closeSerial()
{
    bool ret = false;
    ret = mSerialControl.SerialClose();
    if(ret){
        this->addLog("Serial port closed successfully.");
    }else{
        this->addLog("Failed to close the serial port.");
    }
}

void MainWindow::receiveData()
{
    QString revdata = "";
    mSerialControl.SerialRead(revdata);
    if(revdata != ""){
        this->addLog(QString("[%1]:Arduino -> ThisPC").arg(revdata));
    }else{
        this->addLog("Recieve No Data");
    }

}

void MainWindow::checkSerial()
{
    mSerialControl.SerialCheck();
    this->addLog("[CHECK]:ThisPC -> Arduino");
}

void MainWindow::changeStatusColor()
{
    if(mSerialControl.getPortStatus()){
        ui->portStateLamp->setStyleSheet("background-color : green;");
    }else{
        ui->portStateLamp->setStyleSheet("background-color : red;");
    }
}

