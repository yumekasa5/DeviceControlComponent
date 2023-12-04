#include "MasterThread.h"

MasterThread::MasterThread(QObject *parent)
    : QObject{parent}
{

}

void MasterThread::transaction(const QString &portName, int waitTimeout, const QString &request)
{
    const QMutexLocker locker(&m_mutex);
    m_portName = portName;
    m_waitTimeout = waitTimeout;
    m_request = request;
    if(!isRunning()){
        start();
    }else{
        m_cond.wakeOne();
    }
}
