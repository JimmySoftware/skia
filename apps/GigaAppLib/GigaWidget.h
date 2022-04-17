#ifndef __GIGA_WIDGET_H__
#define __GIGA_WIDGET_H__

#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "tools/skui/ModifierKey.h"
#include "tools/skui/InputState.h"

class GigaUI;
class GigaFont;

class GigaWidget {
public:    
    GigaWidget();
    virtual ~GigaWidget();

    virtual void pre_draw(SkCanvas &canvas);
    virtual void draw(SkCanvas &canvas);
    virtual void post_draw(SkCanvas &canvas);
    virtual bool onMouse(int x, int y, skui::InputState, skui::ModifierKey);
    virtual bool onTouch(intptr_t owner, skui::InputState state, float x, float y);

    int x() { return _x; }
    int y() { return _y; }
    int ax() { return _ax; }
    int ay() { return _ay; }
    int width() { return _width; }
    int height() { return _height; }
    uint32_t bg_color() { return _bg_color; }
    uint32_t border_color() { return _border_color; }
    bool movable() { return _movable; }
    GigaUI *ui() { return _ui; }

    GigaWidget &x( int ix );
    GigaWidget &y( int iy );
    GigaWidget &width( int w );
    GigaWidget &height( int h );
    GigaWidget &bounds( int ix, int iy, int w, int h );
    inline GigaWidget &bg_color( uint32_t c ) { _bg_color = c; return *this; }
    inline GigaWidget &border_color( uint32_t c ) { _border_color = c; return *this; }
    GigaWidget &child( GigaWidget &c );
    GigaWidget &_( GigaWidget &c ) { return child(c); }
    inline GigaWidget &movable( bool b ) { _movable = b; return *this; }
    GigaWidget &font( GigaFont &_font ) {
        return *this;
    }

    void setParent( GigaWidget *p );
    bool hitTest( int x, int y );

    void ui( GigaUI *iui );

protected:
    GigaUI *_ui;

    int _x;
    int _y;
    int _width;
    int _height;

    int _ax;
    int _ay;

    int _ow;
    int _oh;

    uint32_t _bg_color;
    uint32_t _border_color;
    bool _movable;
    bool _moving;
    int _lastX;
    int _lastY;

    std::vector<GigaWidget *>_children;
    GigaWidget *_parent;

    virtual void _draw_bg(SkCanvas &canvas);
    virtual void _draw_content(SkCanvas &canvas);
    virtual void _draw_children(SkCanvas &canvas);
    virtual void _draw_border(SkCanvas &canvas);    

#ifdef __EMSCRIPTEN__
    void emscriptenDownloadAsset( GigaImage *widget, 
        std::string url, 
        void (*onsuccess)(struct emscripten_fetch_t *fetch),
        void (*onerror)(struct emscripten_fetch_t *fetch) ) 
#endif     
};

extern std::vector<GigaWidget *>widgets_storage;
GigaWidget &Widget();

#endif //__GIGA_WIDGET_H__