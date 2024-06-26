//#include "MasterThread.h"

//#include <QSerialPort>
//#include <QObject>
//#include <QTime>

//MasterThread::MasterThread(QObject *parent)
//{

//}

//void MasterThread::transaction(const QString &portName, int waitTimeout, const QString &request)
//{
//    const QMutexLocker locker(&m_mutex);
//    m_portName = portName;
//    m_waitTimeout = waitTimeout;
//    m_request = request;
//    if(!isRunning()){
//        start();
//    }else{
//        m_cond.wakeOne();
//    }
//}

//void MasterThread::run(){
//    bool currentPortNameChanged = false;

//    m_mutex.lock();
//    QString currentPortName;
//    if(currentPortName != m_portName){
//        currentPortName = m_portName;
//        currentPortNameChanged = true;
//    }

//    int currentWaitTimeout = m_waitTimeout;
//    QString currentRequest = m_request;
//    m_mutex.unlock();

//    QSerialPort serial;

//    if(currentPortName.isEmpty()){
//        emit error("No port name specified");
//        return;
//    }

//    while(!m_quit){
//        if(currentPortNameChanged){
//            serial.close();
//            serial.setPortName(currentPortName);

//            if(!serial.open(QIODevice::ReadWrite)){
//                emit error(QString("Can't open %1. error code %2")
//                               .arg(m_portName).arg(serial.error()));
//                return;
//            }
//        }

//        // write request
//        const QByteArray requestData = currentRequest.toUtf8();
//        serial.write(requestData);
//        if(serial.waitForBytesWritten(m_waitTimeout)){

//        }else{
//            emit timeout(QString("Wait write request timouet %1")
//                             .arg(QTime::currentTime().toString()));
//        }

//        //read response
//        if(serial.waitForReadyRead(currentWaitTimeout)){
//            QByteArray responseData = serial.readAll();
//            while(serial.waitForReadyRead(10))
//                responseData += serial.readAll();
//            const QString response = QString::fromUtf8(responseData);
//            emit this->response(response);
//        }else{
//            emit timeout(QString("Wait read response timeout %1")
//                             .arg(QTime::currentTime().toString()));
//        }
//    }
//    m_mutex.lock();
//    m_cond.wait(&m_mutex);
//    if(currentPortName != m_portName){
//        currentPortName = m_portName;
//        currentPortNameChanged = true;
//    }else{
//        currentPortNameChanged = false;
//    }
//    currentWaitTimeout = m_waitTimeout;
//    currentRequest = m_request;
//    m_mutex.unlock();
//}
