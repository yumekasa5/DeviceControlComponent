#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <QObject>

class ServoMotor : public QObject
{
    Q_OBJECT
public:
    explicit ServoMotor(QObject *parent = nullptr);

signals:

};

#endif // SERVOMOTOR_H
