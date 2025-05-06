#ifndef BASEDATAUTILITIES_H
#define BASEDATAUTILITIES_H

#include <QObject>
#include <QPalette>
#include <QDir>
#include <QProcess>
#include <QTimer>
#include <QtGlobal> 
#include <QDateTime> 
#include <QSharedMemory> 
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickItem> 
#include <QTranslator>
#include <QQuickStyle>
#include <QQuickWindow>
#include <QSGRendererInterface>
#include <QQmlEngine>

class BaseDataUtilities : public QObject
{
    Q_OBJECT
public:
    explicit BaseDataUtilities(QObject* parent);
    ~BaseDataUtilities();
};

#endif
