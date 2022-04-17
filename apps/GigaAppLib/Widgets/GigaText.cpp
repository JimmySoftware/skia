#include "include/core/SkFont.h"
#include "include/core/SkColor.h"
#include "../GigaFont.h"
#include "GigaText.h"

GigaText::GigaText() {
    _size = 14;
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
    SkFont font;
    font.setTypeface(_font->Regular());
    font.setSubpixel(true);
    font.setSize(_size);

    SkPaint paint;
    paint.setAntiAlias(true);
    paint.setColor(SK_ColorBLACK);

    canvas.drawSimpleText(_text.c_str(), _text.length(), SkTextEncoding::kUTF8, 0, 20, font, paint);
}    