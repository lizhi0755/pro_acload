
#include <QObject>
#include <basic/SingleProcessManager.h>
#include <model/ACLoadViewHelper.h>
#include <model/ViewModelUtilities.h>

int main(int argc, char *argv[])
{
    //QGuiApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    //QQuickWindow::setSceneGraphBackend("Software");
    QGuiApplication app(argc, argv);
    SingleProcessManager::instance()->create("ACLoadTool_Locker", false, true);
    if (SingleProcessManager::instance()->isCreated()) {
        ACLoadViewHelper::instance()->create(&app);
        qint32 exitcode = app.exec();
        SingleProcessManager::instance()->destroy();
        if (exitcode == ViewModelUtilities::EXIT_CODE_REBOOT) {
            ACLoadViewHelper::instance()->destroy();
            ACLoadViewHelper::instance()->restartApp();
            return 0;
        }
        else {
            return exitcode;
        }
    }
    return 0;
}

