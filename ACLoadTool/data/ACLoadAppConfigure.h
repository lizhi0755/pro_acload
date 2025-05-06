#ifndef ACLOADAPPCONFIGURE_H
#define ACLOADAPPCONFIGURE_H

#include <QObject>
#include <QQmlEngine>
#include <QPalette>
#include <QColor>

class ACLoadAppConfigure : public QObject
{
    Q_OBJECT
public:
    enum { CNTPALETTEGROUP = 3 };
    enum { CNTPALETTEROLE = 19 };
    enum { CNTPALETTESTYLE = 4 };
public:
    enum VIEWLanguageType {
        VIEWLANGUGE_TYPE_CHINESE = 0,
        VIEWLANGUGE_TYPE_ENGLISH,
    };
    enum VIEWStyleType {
        VIEWSTYLE_TYPE_DEFAULT = 0,
        VIEWSTYLE_TYPE_FUSION,
        VIEWSTYLE_TYPE_IMAGINE,
        VIEWSTYLE_TYPE_MATERIAL,
        VIEWSTYLE_TYPE_UNIVERSAL,
    };
    enum PALETTEGroupType {
        PALETTEGROUP_TYPE_ACTIVE = 0,
        PALETTEGROUP_TYPE_DISABLED,
        PALETTEGROUP_TYPE_INACTIVE,
    };
    enum PALETTERoleType {
        PALETTEROLE_TYPE_WINDOW = 0,        // colorA general background color.
        PALETTEROLE_TYPE_WINDOWTEXT,        // colorA general foreground color.
        PALETTEROLE_TYPE_BASE,              // colorUsed mostly as the background color for text editor controls and items views. It is usually white or another light color.
        PALETTEROLE_TYPE_ALTERNATEBASE,     // colorUsed as the alternate background color in item views with alternating row colors.
        PALETTEROLE_TYPE_TOOLTIPBASE,       // colorUsed as the background color for tooltips.
        PALETTEROLE_TYPE_TOOLTIPTEXT,       // colorUsed as the foreground color for tooltips.
        PALETTEROLE_TYPE_TEXT,              // colorThe foreground color used with palette.base. This is usually the same as the palette.windowText, in which case it must provide good contrast with palette.window and palette.base.
        PALETTEROLE_TYPE_BUTTON,            // colorThe general button background color. This background can be different from palette.window as some styles require a different background color for buttons.
        PALETTEROLE_TYPE_BUTTONTEXT,        // colorA foreground color used with the palette.button color.
        PALETTEROLE_TYPE_BRIGHTTEXT,        // colorA text color that is very different from palette.windowText, and contrasts well with e.g. palette.dark. Typically used for text that needs to be drawn where palette.text, palette.windowText or palette.buttonText would give poor contrast, such as on highlighted buttons.
        PALETTEROLE_TYPE_HIGHLIGHT,         // colorA color to indicate a selected item or the current item.
        PALETTEROLE_TYPE_HIGHLIGHTEDTEXT,   // colorA text color that contrasts with palette.highlight.
        PALETTEROLE_TYPE_LIGHT,             // colorLighter than palette.button.
        PALETTEROLE_TYPE_MIDLIGHT,          // colorBetween palette.button and palette.light.
        PALETTEROLE_TYPE_DARK,              // colorDarker than palette.button.
        PALETTEROLE_TYPE_MID,               // colorBetween palette.button and palette.dark.
        PALETTEROLE_TYPE_SHADOW,            // colorA very dark color.
        PALETTEROLE_TYPE_LINK,              // colorA text color used for hyperlinks.
        PALETTEROLE_TYPE_LINKVISITED,       // colorA text color used for already visited hyperlinks.
    };
    enum PALETTEStyleType {
        PALETTESTYLE_TYPE_NORMAL = 0,
        PALETTESTYLE_TYPE_BLACK,
        PALETTESTYLE_TYPE_BLUE,
        PALETTESTYLE_TYPE_GREEN,
    };
public:
    Q_ENUM(VIEWLanguageType)
    Q_ENUM(VIEWStyleType)
    Q_ENUM(PALETTEGroupType)
    Q_ENUM(PALETTERoleType)
    Q_ENUM(PALETTEStyleType)
public:
    explicit ACLoadAppConfigure(QObject *parent = nullptr);

public:
    void setPalette(QPalette * palette);

public:
    QString appTitle;
    QString appFontName;
    qint32  appFontSize;
    qint32  appFontWeight;
public:
    VIEWStyleType appViewStyle;
    PALETTEStyleType appPaletteStyle;
    QString appPaletteColors[CNTPALETTESTYLE][CNTPALETTEGROUP][CNTPALETTEROLE];

public:
    VIEWLanguageType appViewLanguage;

};
 
#endif // ACLOADAPPCONFIGURE_H
