#include "fontawesomeicons.h"
#include <QFontDatabase>

FontAwesomeIcons &FontAwesomeIcons::Instance() {
    static FontAwesomeIcons _instance;
    return _instance;
}

FontAwesomeIcons::FontAwesomeIcons() {
    int fontId = QFontDatabase::addApplicationFont(":/fontawesome-webfont.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);

    this->font.setFamily(fontFamilies.at(0));
    this->font.setPointSize(12);
}

QFont FontAwesomeIcons::getFont() {
    return this->font;
}

QChar FontAwesomeIcons::getIconChar(FontAwesomeIcons::IconIdentity code) {
    return QChar(static_cast<int>(code));
}


