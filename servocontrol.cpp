#include <QThread>
#include <QDebug>

#include "servocontrol.h"
#include "ServoMotor.h"


ServoControl::ServoControl(QObject *parent)
    : QObject{parent},
    mServoIndex(0),
    mServoStatus(Stop),
    mServoAngle(0),
    mServoMotor(new ServoMotor),
    mServoThread(new QThread(this))
{
    qDebug() << "Create ServoControl Instance";
    qDebug() << "ServoControl move to Thread";
    mServoMotor->moveToThread(mServoThread);
    connect(mServoThread, SIGNAL(finished()), mServoMotor, SLOT(deleteLater()));

    mServoThread->start();
}

ServoControl::~ServoControl()
{
    mServoThread->exit();
    mServoThread->wait();
}
