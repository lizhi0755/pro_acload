#ifndef ACLOADDATAHELPER_H
#define ACLOADDATAHELPER_H

#include <QObject>
#include <QQmlEngine>
#include <data/ACLoadAppConfigure.h>
#include <data/ACLoadDataEntity.h>

class ACLoadDataHelper: public QObject
{
    Q_OBJECT
public:
    explicit ACLoadDataHelper(QObject *parent = nullptr);

public: 
    static ACLoadDataHelper* instance();

public:
    ACLoadAppConfigure  * appCfgs;
    ACLoadDataEntity    * dataEnt;

public:
    void save();
    void load();

};


#endif
