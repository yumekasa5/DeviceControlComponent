/*サーボモータの制御クラス
 *
 **/

#ifndef SERVOCONTROL_H
#define SERVOCONTROL_H

#include <SingletonBase.h>

#include <QObject>

class QThread;
class ServoMotor;

// ServoMotorの状態
enum EServoStatus{
    Stop,
    Move,
    Origin,
    Idle
};

// Singletonで実装
class ServoControl : public QObject, SingletonBase<ServoControl>
{
    Q_OBJECT
public:
    ServoControl(QObject *parent = nullptr);
    ~ServoControl();

signals:

private:
    int mServoIndex;
    EServoStatus mServoStatus;
    int mServoAngle;
    ServoMotor* mServoMotor;
    QThread* mServoThread;

};

#endif // SERVOCONTROL_H
