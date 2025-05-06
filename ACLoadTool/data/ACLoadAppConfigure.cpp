
#include "data/ACLoadAppConfigure.h"

ACLoadAppConfigure::ACLoadAppConfigure(QObject *parent) : QObject(parent)
{
    appTitle = tr("交流负载监视工具");
    appFontName = "Microsoft YaHei";
    appFontSize = 13;
    appFontWeight = 66;
    appViewStyle = VIEWSTYLE_TYPE_DEFAULT;
    appPaletteStyle = PALETTESTYLE_TYPE_NORMAL;
    for (qint32 s = 0; s < CNTPALETTESTYLE; s++) {
        for (qint32 n = 0; n < CNTPALETTEGROUP; n++) {
            for (qint32 x = 0; x < CNTPALETTEROLE; x++) {
                appPaletteColors[s][n][x] = "";
            }
        }
    }
    appViewLanguage = VIEWLANGUGE_TYPE_CHINESE;
}

void ACLoadAppConfigure::setPalette(QPalette * palette)
{
    QPalette::ColorGroup groups[] = {
        QPalette::Normal,
        QPalette::Disabled,
        QPalette::Inactive
    };
    QPalette::ColorRole roles[] = {
        QPalette::Window,
        QPalette::WindowText,
        QPalette::Base,
        QPalette::AlternateBase,
        QPalette::ToolTipBase,
        QPalette::ToolTipText,
        QPalette::Text,
        QPalette::Button,
        QPalette::ButtonText,
        QPalette::BrightText,
        QPalette::Highlight,
        QPalette::HighlightedText,
        QPalette::Light,
        QPalette::Midlight,
        QPalette::Dark,
        QPalette::Mid,
        QPalette::Shadow,
        QPalette::Link,
        QPalette::LinkVisited
    };
    QColor color;
    for (qint32 n = 0; n < CNTPALETTEGROUP; n++) {
        for (qint32 x = 0; x < CNTPALETTEROLE; x++) {
            if (appPaletteColors[(qint32)appPaletteStyle][n][x] != "") {
                color.setNamedColor(appPaletteColors[(qint32)appPaletteStyle][n][x]);
                palette->setColor(groups[n], roles[x], color);
            }
            else {
                appPaletteColors[(qint32)appPaletteStyle][n][x] = palette->color(groups[n], roles[x]).name(QColor::HexArgb);
            }
        }
    }
}
