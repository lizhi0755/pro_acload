#ifndef VIEWMODELUTILITIES_H
#define VIEWMODELUTILITIES_H

#include <QObject>
#include <QQmlEngine>

class ViewModelUtilities  : public QObject
{
    Q_OBJECT
public:
    enum { EXIT_CODE_REBOOT = 0x12345678 };

public:
    explicit ViewModelUtilities(QObject *parent);
    ~ViewModelUtilities();

public:
    Q_INVOKABLE void tryQuitForReboot(void);

public:
    Q_INVOKABLE void releaseProcessLocker(void);
      
public slots:
    void slotDestroy(void);

};

#endif // VIEWMODELUTILITIES_H
