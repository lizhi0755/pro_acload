#ifndef SINGLEPROCESSMANAGER_H
#define SINGLEPROCESSMANAGER_H

#include <QObject>
#include <QTimer>
#include <QSharedMemory>
#include <QWindow>
#include <QGuiApplication>

class SingleProcessManager : public QObject
{
    Q_OBJECT
public:
    enum SHAREDType {
        SHARED_TYPE_NONE = 0,
        SHARED_TYPE_CREATE,
        SHARED_TYPE_ATTACH,
    };
public:
    Q_ENUM(SHAREDType)
public:
    explicit SingleProcessManager(QObject * parent = nullptr);
    explicit SingleProcessManager(const QString & managername, bool onlyattach, bool winactive, quint32 interval = 800, QObject * parent = nullptr);
    virtual ~SingleProcessManager(void);

public:
    static SingleProcessManager * instance();

public:
    static bool attach(const QString & managername);

public:
    bool create(const QString & managername, bool onlyattach, bool winactive, quint32 interval = 800);
    void destroy(void);

public:
    bool isCreated(void);

private slots:
    void slotActiveTrigger(void);

signals:
    void sigManagerTrigger(void);

public slots:
    void setWindowActive(void);

private:
    QTimer * queryTimer;
    quint32  queryInterval;
    quint32  activeCounter;
    SHAREDType      sharedType;
    QSharedMemory * sharedMemory;
};


#endif
