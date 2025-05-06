#include "model/ViewModelAppConfigure.h"
#include "data/ACLoadDataHelper.h"

ViewModelAppConfigure::ViewModelAppConfigure(QObject *parent) : QObject(parent)
{

}

QString ViewModelAppConfigure::getAppTitle()
{
    return ACLoadDataHelper::instance()->appCfgs->appTitle;
}
QString ViewModelAppConfigure::getAppFontName()
{
    return ACLoadDataHelper::instance()->appCfgs->appFontName;
}
qint32 ViewModelAppConfigure::getAppFontSize()
{
    return ACLoadDataHelper::instance()->appCfgs->appFontSize;
}
qint32 ViewModelAppConfigure::getAppFontWeight()
{
    return ACLoadDataHelper::instance()->appCfgs->appFontWeight;
}
ACLoadAppConfigure::VIEWStyleType ViewModelAppConfigure::getAppViewStyle()
{
    return ACLoadDataHelper::instance()->appCfgs->appViewStyle;
}
ACLoadAppConfigure::PALETTEStyleType  ViewModelAppConfigure::getAppPaletteStyle()
{
    return ACLoadDataHelper::instance()->appCfgs->appPaletteStyle;
}


void ViewModelAppConfigure::setAppTitle(QString value)
{
    ACLoadDataHelper::instance()->appCfgs->appTitle = value;
}
void ViewModelAppConfigure::setAppFontName(QString value)
{
    ACLoadDataHelper::instance()->appCfgs->appFontName = value;
}
void ViewModelAppConfigure::setAppFontSize(qint32 value)
{
    ACLoadDataHelper::instance()->appCfgs->appFontSize = value;
}
void ViewModelAppConfigure::setAppFontWeight(qint32 value)
{
    ACLoadDataHelper::instance()->appCfgs->appFontWeight = value;
}
void ViewModelAppConfigure::setAppViewStyle(ACLoadAppConfigure::VIEWStyleType value)
{
    ACLoadDataHelper::instance()->appCfgs->appViewStyle = value;
}
void ViewModelAppConfigure::setAppPaletteStyle(ACLoadAppConfigure::PALETTEStyleType value)
{
    ACLoadDataHelper::instance()->appCfgs->appPaletteStyle = value;
}
