#ifndef __GIGA_WIDGET_H__
#define __GIGA_WIDGET_H__

#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"

class GigaWidget {
public:    
    GigaWidget();
    virtual ~GigaWidget();

    virtual void draw(SkCanvas &canvas);

    int x() { return _x; }
    int y() { return _y; }
    int width() { return _width; }
    int height() { return _height; }

    inline GigaWidget &x( int x ) { _x = x; return *this; }
    inline GigaWidget &y( int y ) { _y = y; return *this; }
    inline GigaWidget &width( int w ) { _width = w; return *this; }
    inline GigaWidget &height( int h ) { _height = h; return *this; }
    inline GigaWidget &bounds( int x, int y, int w, int h ) { _x=x; _y=y; _width=w; _height=h; return *this; }

protected:
    int _x;
    int _y;
    int _width;
    int _height;
};

GigaWidget &Widget();

#endif //__GIGA_WIDGET_H__