#include "model/ViewModelUtilities.h"
#include "model/ACLoadViewHelper.h"
#include "basic/SingleProcessManager.h"

ViewModelUtilities::ViewModelUtilities(QObject *parent) : QObject(parent)
{
}

ViewModelUtilities::~ViewModelUtilities()
{
}

void ViewModelUtilities::tryQuitForReboot(void)
{                          
    QCoreApplication::exit(ViewModelUtilities::EXIT_CODE_REBOOT);    
    qDebug() << "ViewModelUtilities tryQuitForReboot ";       
}

void ViewModelUtilities::releaseProcessLocker(void)
{
    SingleProcessManager::instance()->destroy();
}
 
void ViewModelUtilities::slotDestroy(void)
{
    ACLoadViewHelper::instance()->destroy();
    // qApp->quit();
    // QTimer::singleShot(0, qApp, &QCoreApplication::quit);
    // QTimer::singleShot(100, qApp, SLOT(quit()));
}
