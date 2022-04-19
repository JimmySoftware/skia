#include "include/core/SkFont.h"
#include "include/core/SkColor.h"
#include "include/core/SkFontMetrics.h"
#include "../GigaFont.h"
#include "GigaText.h"

GigaText::GigaText() {
    _size = 12;
    _tfIndex = FONT_REGULAR;

    _background = false;
    _border = false;
}

GigaText::~GigaText() {

}

GigaText &Text( const char *text ) {
    GigaText *w = new GigaText();
    w->text( text );
    widgets_storage.push_back( w );
    return *w;
}

GigaText &GigaText::Regular() {
    _tfIndex = FONT_REGULAR;
    return *this;
}

GigaText &GigaText::Bold() {
    _tfIndex = FONT_BOLD;
    return *this;
}
GigaText &GigaText::Italic() {
    _tfIndex = FONT_ITALIC;
    return *this;
}
GigaText &GigaText::BoldItalic() {
    _tfIndex = FONT_BOLDITALIC;
    return *this;
}
GigaText &GigaText::Icon() {
    _tfIndex = FONT_ICON;
    return *this;
}

GigaText &GigaText::size( const int s ) {
    _size = s;
    return *this;
}

GigaText &GigaText::text( const char *text ) {
    _text = std::string( text );
    if( _ow == 0 ) {
        _width = _contentWidth();
    }
    if( _oh == 0 ) {
        _height = _contentHeight();
    }    
    return *this;
}

int GigaText::_contentWidth() {
    if( _font == NULL ) {
        return 0;
    }
    
    SkFont font;
    font.setTypeface(_font->typeface(_tfIndex));
    font.setSubpixel(true);
    font.setSize(_size);
    SkRect rect;
    int ww = font.measureText( _text.c_str(), _text.length(), SkTextEncoding::kUTF8, &rect );   

    return rect.fRight - rect.fLeft;
}

int GigaText::_contentHeight() {
    if( _font == NULL ) {
        return 0;
    }
    
    SkFont font;
    font.setTypeface(_font->typeface(_tfIndex));
    font.setSubpixel(true);
    font.setSize(_size);
    
    SkFontMetrics metrics;
    font.getMetrics(&metrics);
    float fontHeight = -metrics.fAscent + metrics.fDescent;

    SkRect rect;
    int ww = font.measureText( _text.c_str(), _text.length(), SkTextEncoding::kUTF8, &rect );   
    return fontHeight;
}

void GigaText::_draw_content(SkCanvas &canvas) {
    if( _width == 0 && _ow == 0 && _text.length() ) {
        _width = _contentWidth();
    }
    if( _height == 0 && _oh == 0 && _text.length() ) {
        _height = _contentHeight();
    }    
    SkFont font;
    font.setTypeface(_font->typeface(_tfIndex));
    font.setSubpixel(true);
    font.setSize(_size);

    SkFontMetrics metrics;
    font.getMetrics(&metrics);

    SkPaint paint;
    paint.setAntiAlias(true);
    paint.setColor(SK_ColorBLACK);

    canvas.drawSimpleText(_text.c_str(), _text.length(), SkTextEncoding::kUTF8, 
        0, 0-metrics.fAscent, font, paint);
}    