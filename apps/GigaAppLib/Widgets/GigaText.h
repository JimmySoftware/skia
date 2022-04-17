#ifndef __GIGA_TEXT_H__
#define __GIGA_TEXT_H__

#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "include/core/SkImage.h"
#include "include/core/SkData.h"
#include "../GigaWidget.h"


class GigaText : public GigaWidget {
public:    
    GigaText();
    virtual ~GigaText() override;

    const char *text() { return _text.c_str(); }
    GigaText &text( const char *text );

    GigaText &Regular();
    GigaText &Bold();
    GigaText &Italic();
    GigaText &BoldItalic();
    GigaText &Icon();

    GigaText &size( const int s );

    virtual int _contentWidth() override;
    virtual int _contentHeight() override;     

protected:
    std::string _text;
    int _size;
    int _tfIndex;

    virtual void _draw_content(SkCanvas &canvas) override;    
};

GigaText &Text( const char *text );

#endif //__GIGA_TEXT_H__