#include <cassert>
#include <codecvt>
#include <iostream>
#include <locale>
#include <string>
#include "../GigaFont.h"
#include "GigaIcon.h"

GigaIcon::GigaIcon( const uint16_t code ) {
    _size = 16;
    _tfIndex = FONT_ICON;

    if (code == 0) {
        _text = "";
    } else {
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
        _text = convert.to_bytes(code);
    }
}

GigaIcon::~GigaIcon() {
    
}

GigaIcon &Icon( const uint16_t code ) {
    GigaIcon *w = new GigaIcon( code );
    widgets_storage.push_back( w );
    return *w;    
}