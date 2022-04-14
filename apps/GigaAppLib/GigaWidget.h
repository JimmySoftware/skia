#ifndef __GIGA_WIDGET_H__
#define __GIGA_WIDGET_H__

#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"

class GigaWidget {
public:    
    GigaWidget();
    virtual ~GigaWidget();

    virtual void pre_draw(SkCanvas &canvas);
    virtual void draw(SkCanvas &canvas);
    virtual void post_draw(SkCanvas &canvas);
    virtual bool onMouse(int x, int y, skui::InputState, skui::ModifierKey);

    int x() { return _x; }
    int y() { return _y; }
    int width() { return _width; }
    int height() { return _height; }
    uint32_t bg_color() { return _bg_color; }
    uint32_t border_color() { return _border_color; }

    inline GigaWidget &x( int x ) { _x = x; return *this; }
    inline GigaWidget &y( int y ) { _y = y; return *this; }
    inline GigaWidget &width( int w ) { _width = w; return *this; }
    inline GigaWidget &height( int h ) { _height = h; return *this; }
    inline GigaWidget &bounds( int x, int y, int w, int h ) { _x=x; _y=y; _width=w; _height=h; return *this; }
    inline GigaWidget &bg_color( uint32_t c ) { _bg_color = c; return *this; }
    inline GigaWidget &border_color( uint32_t c ) { _border_color = c; return *this; }
    GigaWidget &child( GigaWidget &c );

protected:
    int _x;
    int _y;
    int _width;
    int _height;
    uint32_t _bg_color;
    uint32_t _border_color;

    std::vector<GigaWidget *>_children;

    virtual void _draw_bg(SkCanvas &canvas);
    virtual void _draw_content(SkCanvas &canvas);
    virtual void _draw_children(SkCanvas &canvas);
    virtual void _draw_border(SkCanvas &canvas);    
};

GigaWidget &Widget();

#endif //__GIGA_WIDGET_H__