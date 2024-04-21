#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "serialcontrol.h"
#include "SerialMonitorWidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mSerialControl(new SerialControl(this))
//    mSerialMonitor(new SerialMonitorWidget)
{
    ui->setupUi(this);

    //! アプリ名とバージョンを取得してQLabelに設定
    QString appName = QCoreApplication::applicationName();
    QString appVersion = QCoreApplication::applicationVersion();
    ui->labelAppNameVersion->setText(appName + " ver. " + appVersion);

    if(mSerialControl->openSerialPort()){
        connect(mSerialControl, &SerialControl::readyRead, this, &MainWindow::printData);
        qDebug() << "Serial port opened successfully.";
    }else{
        qDebug() << "Couldn't open ther port COM3";
    }

    // ランプの背景色設定
    ui->portStateLamp->setStyleSheet("background-color : red;");
    mLogPlainTextEdit = ui->logPlainTextEdit;
    mLogPlainTextEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete mSerialControl;
    disconnect(mSerialPort, &QSerialPort::readyRead, this, &MainWindow::printData);
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

void MainWindow::receiveData()
{
//    QString revdata = "";
//    mSerialControl->SerialRead(revdata);
//    if(revdata != ""){
//        this->addLog(QString("[%1]:Arduino -> ThisPC").arg(revdata));
//    }else{
//        this->addLog("Recieve No Data");
//    }

}

void MainWindow::checkSerial()
{
//    mSerialControl->SerialCheck();
//    this->addLog("[CHECK]:ThisPC -> Arduino");
}

void MainWindow::changeStatusColor()
{
//    if(mSerialPort->getPortStatus()){
//        ui->portStateLamp->setStyleSheet("background-color : green;");
//    }else{
//        ui->portStateLamp->setStyleSheet("background-color : red;");
//    }
}

// SerialMonitorを生成する関数
void MainWindow::openSerialMonitorWidget()
{
    // Widgetの表示
//    mSerialMonitor->show();

}

void MainWindow::on_openSerialMonitorButton_clicked()
{
//    openSerialMonitorWidget();
}


void MainWindow::printData()
{
    mSerialControl->readSerialData(str_buff);
    ui->textEdit->append(str_buff);
    str_buff.clear();
}
