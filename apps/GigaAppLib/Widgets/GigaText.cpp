#include "GigaText.h"

GigaText::GigaText() {

}

GigaText::~GigaText() {

}

GigaText &Text( const char *text ) {
    GigaText *w = new GigaText();
    w->text( text );
    widgets_storage.push_back( w );
    return *w;
}

GigaText &GigaText::text( const char *text ) {
    _text = std::string( text );

    return *this;
}

void GigaText::_draw_content(SkCanvas &canvas) {

}    