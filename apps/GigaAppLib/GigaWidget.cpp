#include "tools/skui/ModifierKey.h"
#include "tools/skui/InputState.h"
#include "GigaWidget.h"
#include "GigaUI.h"

std::vector<GigaWidget *>widgets_storage;

GigaWidget::GigaWidget() {
    _parent = NULL;

    _x = 0; 
    _y = 0;
    _width = 0;
    _height = 0;

    _ax = 0;
    _ay = 0;

    _ow = 0;
    _oh = 0;
    
    _bg_color = 0xFFFFFFFF;
    _border_color = 0xFF000000;

    _movable = false;
    _moving = false;
}

GigaWidget::~GigaWidget() {

}

GigaWidget &Widget() {
    GigaWidget *w = new GigaWidget();
    widgets_storage.push_back( w );
    return *w;
}

void GigaWidget::ui( GigaUI *iui ) { 
    _ui = iui; 
    for( int i=0; i<_children.size(); i++ ) {
        GigaWidget *w = _children[i];
        w->ui( iui );
    }    
}

GigaWidget &GigaWidget::x( int ix ) { 
    if( _parent ) {
        _ax = _parent->_ax + ix;
    }
    else {
        _ax = ix;
    }
    _x = ix; 
    return *this; 
}

GigaWidget &GigaWidget::y( int iy ) { 
    if( _parent ) {
        _ay = _parent->_ay + iy;
    }
    else {
        _ay = iy;
    }
    _y = iy; 
    return *this; 
}

GigaWidget &GigaWidget::width( int w ) { 
    if( w == 0 ) {
        _width = _ow;
    }
    else {
        _width = w; 
    }
    return *this; 
}

GigaWidget &GigaWidget::height( int h ) { 
    if( h == 0 ) {
        _height = _oh;
    }
    else {
        _height = h; 
    }
    return *this; 
}

GigaWidget &GigaWidget::bounds( int ix, int iy, int w, int h ) { 
    x(ix); 
    y(iy); 
    width( w );
    height( h );
    return *this; 
}

bool GigaWidget::onTouch(intptr_t owner, skui::InputState state, float x, float y) {
    if( owner == 0 ) {
        return onMouse( x, y, state, skui::ModifierKey::kNone );
    }
    return false;
}

bool GigaWidget::onMouse(int ix, int iy, skui::InputState state, skui::ModifierKey modifiers ) {
    for( int i=_children.size()-1; i>=0; i-- ) {
        GigaWidget *w = _children[i];
        if( w->hitTest( ix, iy ) ) {
            if( w->onMouse( ix - w->x(), iy - w->y(), state, modifiers ) ) {
                return true;
            }
            return false;
        }
    }  

    if( state == skui::InputState::kDown ) {
        if( _movable ) {
            if( _ui ) {
                _ui->captureMouse( this );
            }
            _moving = true;
            _lastX = ix;
            _lastY = iy;
            return true;
        }
    }
    else if( state == skui::InputState::kMove ) {
        if( _moving ) {
            x( _x + (ix - _lastX) );
            y( _y + (iy - _lastY) );
            //_lastX = x;
            //_lastY = y;
            return true;
        }
    }
    else if( state == skui::InputState::kUp ) {
        if( _moving ) {
            _moving = false;
            if( _ui ) {
                _ui->releaseMouse();
            }
            return true;
        }
    }
    return false;
}

void GigaWidget::pre_draw(SkCanvas &canvas) {
    canvas.save();
    canvas.clipRect( SkRect::MakeXYWH( _x, _y, _width+1, _height+1 ) );
    canvas.translate( _x, _y );
}

void GigaWidget::post_draw(SkCanvas &canvas) {
    canvas.restore();
}

void GigaWidget::_draw_bg(SkCanvas &canvas) {
    SkPaint paint;

    paint.setColor( _bg_color );
    paint.setStyle( SkPaint::Style::kFill_Style );

    canvas.drawRect( SkRect::MakeXYWH( 0, 0, _width, _height ), paint) ;
}

void GigaWidget::_draw_content(SkCanvas &canvas) {
    SkPaint paint;

    paint.setColor( _border_color );
    paint.setStyle( SkPaint::Style::kStroke_Style );
    paint.setAntiAlias( true );

    canvas.drawLine( SkPoint::Make(0, 0), SkPoint::Make(_width, _height), paint );
    canvas.drawLine( SkPoint::Make(_width, 0), SkPoint::Make(0, _height), paint );    
}

void GigaWidget::_draw_children(SkCanvas &canvas) {
    for( int i=0; i<_children.size(); i++ ) {
        GigaWidget *w = _children[i];
        w->pre_draw( canvas );
        w->draw( canvas );
        w->post_draw( canvas );
    }
}

void GigaWidget::_draw_border(SkCanvas &canvas) {
    SkPaint paint;

    paint.setColor( _border_color );
    paint.setStyle( SkPaint::Style::kStroke_Style );

    canvas.drawRect( SkRect::MakeXYWH( 0, 0, _width, _height ), paint) ;
}

void GigaWidget::draw(SkCanvas &canvas) {
    _draw_bg( canvas );
    _draw_content( canvas );
    _draw_children( canvas );
    _draw_border( canvas );
}

GigaWidget &GigaWidget::child( GigaWidget &c ) {
    c.setParent( this );
    _children.push_back( &c );
    return *this;
}

void GigaWidget::setParent( GigaWidget *c ) {
    _parent = c;
    
    if( _parent ) {
        ui( _parent->ui() );
        _ax = _parent->_ax + _x;
        _ay = _parent->_ay + _y;
    }
    else {
        ui( NULL );
        _ax = _x;
        _ay = _y;
    }
}

bool GigaWidget::hitTest( int x, int y ) {
    if( (x > _x) && (x <= (_x + _width)) &&
        (y > _y) && (y <= (_y + _height)) ) {
            return true;
    }
    return false;
}
