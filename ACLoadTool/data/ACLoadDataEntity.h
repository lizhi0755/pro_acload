#ifndef ACLOADDATAENTITY_H
#define ACLOADDATAENTITY_H

#include <QObject>
#include <QQmlEngine>

class ACLoadDataEntity : public QObject
{
    Q_OBJECT
public:
    explicit ACLoadDataEntity(QObject *parent = nullptr);

public:
    enum { ALARM_STATE_COUNT = 5 };

public:
    enum ALARMType {
        ALARM_TYPE_OVERVOLTAGE = 0,
        ALARM_TYPE_UNDERVOLTAGE,
        ALARM_TYPE_OVERCURRENT,
        ALARM_TYPE_LOSSPHASE,
    };

public:
    Q_ENUM(ALARMType)

public:
    quint32 alarmStates[ALARM_STATE_COUNT];
    quint32 tsyncState;
    quint32 tsyncTime;


};

#endif // ACLOADDATAENTITY_H
