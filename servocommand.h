#ifndef SERVOCOMMAND_H
#define SERVOCOMMAND_H

#include <QObject>

class ServoCommand : public QObject
{
    Q_OBJECT
public:
    explicit ServoCommand(QObject *parent = nullptr);
    enum mCommand{
        Move,
        Stop,
        Calibrate,
        Reset
    };

private:
    mCommand mCurrentCommand;

};

#endif // SERVOCOMMAND_H
