
#include "data/ACLoadDataHelper.h"

ACLoadDataHelper::ACLoadDataHelper(QObject *parent) : QObject(parent)
{
   dataEnt = new  ACLoadDataEntity(this);
   appCfgs = new  ACLoadAppConfigure(this);
}

ACLoadDataHelper * ACLoadDataHelper::instance()
{
    static ACLoadDataHelper * ins = nullptr;
    if (ins == nullptr) { 
        ins = new ACLoadDataHelper();
    }
    return ins;
}

void ACLoadDataHelper::save()
{

}

void ACLoadDataHelper::load()
{

}
