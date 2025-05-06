#ifndef VIEWMODELAPPCONFIGURE_H
#define VIEWMODELAPPCONFIGURE_H

#include <QObject>
#include <QQmlEngine>
#include <data/ACLoadAppConfigure.h>

class ViewModelAppConfigure : public QObject
{
    Q_OBJECT
public:
    explicit ViewModelAppConfigure(QObject *parent = nullptr);

public:
    Q_INVOKABLE QString getAppTitle();
    Q_INVOKABLE QString getAppFontName();
    Q_INVOKABLE qint32 getAppFontSize();
    Q_INVOKABLE qint32 getAppFontWeight();
    Q_INVOKABLE ACLoadAppConfigure::VIEWStyleType getAppViewStyle();
    Q_INVOKABLE ACLoadAppConfigure::PALETTEStyleType  getAppPaletteStyle();

public:
    Q_INVOKABLE void setAppTitle(QString value);
    Q_INVOKABLE void setAppFontName(QString value);
    Q_INVOKABLE void setAppFontSize(qint32 value);
    Q_INVOKABLE void setAppFontWeight(qint32 value);
    Q_INVOKABLE void setAppViewStyle(ACLoadAppConfigure::VIEWStyleType value);
    Q_INVOKABLE void setAppPaletteStyle(ACLoadAppConfigure::PALETTEStyleType value);

};

#endif
