
#include "basic/SingleProcessManager.h"


SingleProcessManager * globalSingleProcessManager = nullptr;

SingleProcessManager * SingleProcessManager::instance()
{
    if (globalSingleProcessManager == nullptr) {
        globalSingleProcessManager = new SingleProcessManager();
    }
    return globalSingleProcessManager;
}

SingleProcessManager::SingleProcessManager(QObject *parent) : QObject(parent)
{
    queryInterval = 800;
    queryTimer = nullptr;
    activeCounter = 0;
    sharedMemory = nullptr;
    sharedType = SHARED_TYPE_NONE;
}
SingleProcessManager::SingleProcessManager(const QString & managername, bool onlyattach, bool winactive, quint32 interval, QObject *parent) : QObject(parent)
{
    queryInterval = 800;
    queryTimer = nullptr;
    activeCounter = 0;
    sharedMemory = nullptr;
    sharedType = SHARED_TYPE_NONE;
    create(managername, onlyattach, winactive, interval);
}

SingleProcessManager::~SingleProcessManager(void)
{
    if (queryTimer != nullptr) {
        queryTimer->stop();
        delete queryTimer;
        queryTimer = nullptr;
    }
    if (sharedMemory != nullptr) {
        delete sharedMemory;
        sharedMemory = nullptr;
    }
}

bool SingleProcessManager::attach(const QString & managername)
{
    SingleProcessManager attacher(managername, true, false);
    return (attacher.sharedType == SHARED_TYPE_ATTACH);
}

bool SingleProcessManager::create(const QString & managername, bool onlyattach, bool winactive, quint32 interval)
{
    bool result = false;
    queryInterval = interval;
    if (sharedMemory == nullptr) {
        sharedMemory = new QSharedMemory(managername);
    }
    if (sharedMemory->attach(QSharedMemory::ReadWrite)) {
        sharedMemory->lock();
        if (sharedMemory->size() >= 4) {
            quint32 * counter = (quint32 *)sharedMemory->data();
            if (counter != nullptr) {
                *counter += 1;
            }
        }
        sharedMemory->unlock();
        sharedType = SHARED_TYPE_ATTACH;
        result = true;
    }
    else {
        if (onlyattach) {
            if (sharedMemory != nullptr) {
                delete sharedMemory;
                sharedMemory = nullptr;
            }
        }
        else {
            sharedMemory->create(64);
            sharedMemory->lock();
            if (sharedMemory->size() >= 4) {
                quint32 * counter = (quint32 *)sharedMemory->data();
                if (counter != nullptr) {
                    *counter = activeCounter;
                }
            }
            if (queryTimer == nullptr) {
                queryTimer = new QTimer(this);
                connect(queryTimer, SIGNAL(timeout()), this, SLOT(slotActiveTrigger()));
            }
            queryTimer->start(queryInterval);
            sharedMemory->unlock();
            if (winactive) {
                connect(this, SIGNAL(sigManagerTrigger()), this, SLOT(setWindowActive()));
            }
            sharedType = SHARED_TYPE_CREATE;
            result = true;
        }
    }
    return result;
}

void SingleProcessManager::destroy(void)
{
    disconnect(this, SIGNAL(sigManagerTrigger()), nullptr, nullptr);
    if (queryTimer != nullptr) {
        queryTimer->stop();
        delete queryTimer;
        queryTimer = nullptr;
    }
    if (sharedMemory != nullptr) {
        sharedMemory->detach();
        delete sharedMemory;
        sharedMemory = nullptr;
    }
    sharedType = SHARED_TYPE_NONE;
}

bool SingleProcessManager::isCreated(void)
{
    return (sharedType == SHARED_TYPE_CREATE);
}

void SingleProcessManager::slotActiveTrigger(void)
{
    bool triggered = false;
    if (sharedMemory != nullptr) {
        sharedMemory->lock();
        if (sharedMemory->size() >= 4) {
            quint32 * counter = (quint32 *)sharedMemory->data();
            if (counter != nullptr) {
                if (*counter != activeCounter) {
                    activeCounter = *counter;
                    triggered = true;
                }
            }
        }
        sharedMemory->unlock();
    }
    if (triggered) {
        emit sigManagerTrigger();
    }
}

void SingleProcessManager::setWindowActive(void)
{
    QWindow * win = QGuiApplication::modalWindow();
    if (win == nullptr) {
        if (qApp != nullptr) {
            QWindowList winlist = qApp->topLevelWindows();
            if (winlist.count() > 0) {
                win = winlist.at(0);
            }
        }
    }
    if (win != nullptr) {
        // qt.qpa.wayland: Wayland does not support QWindow::requestActivate()
        // so donot call : requestActivate();
#if defined(__unix)
        win->setFlags( win->flags() | Qt::WindowStaysOnTopHint);
        win->show();
        win->raise();
#else
        // window
        win->show();
        win->requestActivate();
        win->raise();
#endif
    }
}


