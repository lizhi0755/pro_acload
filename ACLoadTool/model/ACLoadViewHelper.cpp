
#include "model/ACLoadViewHelper.h"
#include "data/ACLoadDataHelper.h"

ACLoadViewHelper * globalACLoadViewHelper = nullptr;

ACLoadViewHelper * ACLoadViewHelper::instance()
{
    if (globalACLoadViewHelper == nullptr) {
        globalACLoadViewHelper = new ACLoadViewHelper();
    }
    return globalACLoadViewHelper;
}

ACLoadViewHelper::ACLoadViewHelper(QObject *parent) : QObject(parent)
{
    applicationRoot = nullptr;
    applicationEngine = nullptr;
    viewMainWindow = nullptr;
    viewTranslator = nullptr;
    viewAppCfgs = nullptr;
    viewDataEnt = nullptr;
    viewUtilities = nullptr;
}

ACLoadViewHelper::~ACLoadViewHelper()
{
    if (viewDataEnt != nullptr) {
        viewDataEnt->deleteLater();
        viewDataEnt = nullptr;
    }
    if (viewAppCfgs != nullptr) {
        viewAppCfgs->deleteLater();
        viewAppCfgs = nullptr;
    }
    if (viewUtilities != nullptr) {
        viewUtilities->deleteLater();
        viewUtilities = nullptr;
    }
    if (applicationEngine != nullptr) {
        applicationEngine->deleteLater();
        applicationEngine = nullptr;
    }
    if (viewTranslator != nullptr) {
        viewTranslator->deleteLater();
        viewTranslator = nullptr;
    }
}


void ACLoadViewHelper::setStyles()
{
    if (ACLoadDataHelper::instance()->appCfgs->appViewStyle == ACLoadAppConfigure::VIEWSTYLE_TYPE_FUSION) {
        QQuickStyle::setStyle("Fusion"); // ok
    }
    else if (ACLoadDataHelper::instance()->appCfgs->appViewStyle == ACLoadAppConfigure::VIEWSTYLE_TYPE_IMAGINE) {
        QQuickStyle::setStyle("Imagine"); // ok
    }
    else if (ACLoadDataHelper::instance()->appCfgs->appViewStyle == ACLoadAppConfigure::VIEWSTYLE_TYPE_MATERIAL) {
        QQuickStyle::setStyle("Imagine");  // Material donot work, so use Imagine
    }
    else if (ACLoadDataHelper::instance()->appCfgs->appViewStyle == ACLoadAppConfigure::VIEWSTYLE_TYPE_UNIVERSAL) {
        QQuickStyle::setStyle("Universal"); // ok
    }
    else {
        QQuickStyle::setStyle("Default"); // ok
    }
    QString fontName = ACLoadDataHelper::instance()->appCfgs->appFontName;
    qint32 fontSize =  ACLoadDataHelper::instance()->appCfgs->appFontSize;
    qint32 fontWeight = ACLoadDataHelper::instance()->appCfgs->appFontWeight;
    QFont font(fontName, fontSize, fontWeight);
    QGuiApplication::setFont(font);
}

void ACLoadViewHelper::setPalettes()
{
    QPalette palette(QGuiApplication::palette());
    ACLoadDataHelper::instance()->appCfgs->setPalette(&palette);
    QGuiApplication::setPalette(palette);
}

void ACLoadViewHelper::installTranslator()
{
    if (viewTranslator == nullptr) {
        // 使用静态库时候需要手动加载，否则不需要
        // Q_INIT_RESOURCE(ACLoad);
        viewTranslator = new QTranslator();
        bool loaded = false;
        if (ACLoadDataHelper::instance()->appCfgs->appViewLanguage == ACLoadAppConfigure::VIEWLANGUGE_TYPE_CHINESE) {
            loaded = viewTranslator->load(QStringLiteral("qrc:/ACLoad/view/translations/acload_zh.qm"));
        }
        else {
            loaded = viewTranslator->load(QStringLiteral("qrc:/ACLoad/view/translations/acload_en.qm"));
        }
        if (loaded) {
            QCoreApplication::instance()->installTranslator(viewTranslator);
        }
    }
}

void ACLoadViewHelper::removeTranslator()
{
    if (viewTranslator != nullptr) {
        QCoreApplication::instance()->removeTranslator(viewTranslator);
        delete viewTranslator;
        viewTranslator = nullptr;
    }
}

void ACLoadViewHelper::createModels(QGuiApplication * app)
{
    applicationRoot = app;
    viewAppCfgs = new ViewModelAppConfigure(app);
    viewDataEnt = new ViewModelDataEntity(app);
    viewUtilities = new ViewModelUtilities(app);
    applicationEngine = new QQmlApplicationEngine(app);
    applicationEngine->rootContext()->setContextProperty("viewAppCfgs", viewAppCfgs);
    applicationEngine->rootContext()->setContextProperty("viewDataEnt", viewDataEnt);
    applicationEngine->rootContext()->setContextProperty("viewUtilities", viewUtilities);
}

void ACLoadViewHelper::showWindows()
{
    const QUrl url(QStringLiteral("qrc:/ACLoadTool/view/qmls/MainWindow.qml"));
    //const QUrl url(QStringLiteral("qrc:/view/qmls/MainWindow.qml"));
    QObject::connect(
        applicationEngine,
        &QQmlApplicationEngine::objectCreationFailed,
        applicationRoot,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    applicationEngine->load(url);
    QObject * rootObject = applicationEngine->rootObjects().first();
    viewMainWindow = qobject_cast<QQuickWindow *>(rootObject);
    viewMainWindow->raise();
    viewMainWindow->show();
}

void ACLoadViewHelper::registerTypes()
{
    qRegisterMetaType<ACLoadAppConfigure::VIEWLanguageType>("ACLoadAppConfigure::VIEWLanguageType");
    qRegisterMetaType<ACLoadAppConfigure::VIEWStyleType>("ACLoadAppConfigure::VIEWStyleType");
    qRegisterMetaType<ACLoadAppConfigure::PALETTEGroupType>("ACLoadAppConfigure::PALETTEGroupType");
    qRegisterMetaType<ACLoadAppConfigure::PALETTERoleType>("ACLoadAppConfigure::PALETTERoleType");
    qRegisterMetaType<ACLoadAppConfigure::PALETTEStyleType>("ACLoadAppConfigure::PALETTEStyleType");
    qRegisterMetaType<ACLoadDataEntity::ALARMType>("ACLoadDataEntity::ALARMType");
    qmlRegisterType<ACLoadAppConfigure>("ACLoad", 1, 0, "ACLoadAppConfigure");
    qmlRegisterType<ACLoadDataEntity>("ACLoad", 1, 0, "ACLoadDataEntity");
    qmlRegisterType<ViewModelAppConfigure>("ACLoad", 1, 0, "ViewModelAppConfigure");
    qmlRegisterType<ViewModelDataEntity>("ACLoad", 1, 0, "ViewModelDataEntity");
    qmlRegisterType<ViewModelUtilities>("ACLoad", 1, 0, "ViewModelUtilities");
}

void ACLoadViewHelper::create(QGuiApplication * app)
{
    ACLoadDataHelper::instance()->load();
    setStyles();
    setPalettes();
    registerTypes();
    installTranslator();
    createModels(app);
    showWindows();
}

void ACLoadViewHelper::destroy()
{
    removeTranslator();
    ACLoadDataHelper::instance()->save();
    if (viewAppCfgs != nullptr) {
        viewAppCfgs->deleteLater();
        viewAppCfgs = nullptr;
    }
    if (viewDataEnt != nullptr) {
        viewDataEnt->deleteLater();
        viewDataEnt = nullptr;
    }
    if (viewUtilities != nullptr) {
        viewUtilities->deleteLater();
        viewUtilities = nullptr;
    }
    if (applicationEngine != nullptr) {
        applicationEngine->deleteLater();
        applicationEngine = nullptr;
    }
    if (viewTranslator != nullptr) {
        viewTranslator->deleteLater();
        viewTranslator = nullptr;
    }
}

void ACLoadViewHelper::restartApp()
{
    QString program = QCoreApplication::applicationFilePath();
    QStringList arguments = QCoreApplication::arguments();
    QString workdir = QDir::currentPath();
    QProcess::startDetached(program, arguments, workdir);
}

