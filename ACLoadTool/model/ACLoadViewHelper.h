#ifndef ACLOADVIEWHELPER_H
#define ACLOADVIEWHELPER_H

#include <QObject>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QTranslator>
#include <QQuickStyle>
#include <QFont>
#include <QQmlContext>
#include <QDir>
#include <QProcess>
#include <model/ViewModelAppConfigure.h>
#include <model/ViewModelDataEntity.h>
#include <model/ViewModelUtilities.h>

class ACLoadViewHelper: public QObject
{
    Q_OBJECT
public:
    explicit ACLoadViewHelper(QObject *parent = nullptr);
    virtual ~ACLoadViewHelper();

public:
    static ACLoadViewHelper* instance();

public:
    void create(QGuiApplication * app);
    void destroy();
    void restartApp();

private:
    void setStyles();
    void setPalettes();
    void installTranslator();
    void removeTranslator();
    void createModels(QGuiApplication * app);
    void showWindows();
    void registerTypes();

public:
    ViewModelAppConfigure  * viewAppCfgs;
    ViewModelDataEntity    * viewDataEnt;
    ViewModelUtilities     * viewUtilities;

public:
    QGuiApplication * applicationRoot;
    QQmlApplicationEngine * applicationEngine;
    QQuickWindow * viewMainWindow;
    QTranslator * viewTranslator;

};

#endif
