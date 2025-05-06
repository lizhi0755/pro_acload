#ifndef VIEWMODELDATAENTITY_H
#define VIEWMODELDATAENTITY_H

#include <QObject>
#include <QQmlEngine>
#include <data/ACLoadDataEntity.h>

class ViewModelDataEntity : public QObject
{
    Q_OBJECT
public:
    explicit ViewModelDataEntity(QObject *parent = nullptr);

signals:

};

#endif
