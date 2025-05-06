
#include "data/ACLoadDataEntity.h"


ACLoadDataEntity::ACLoadDataEntity(QObject *parent) : QObject(parent)
{
    for (int x = 0; x <ALARM_STATE_COUNT; x++ ) {
        alarmStates[x] = 1;
    }
    tsyncState = 1;
    tsyncTime = 11111111;
}
