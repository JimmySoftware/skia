#include "tools/skui/ModifierKey.h"
#include "tools/skui/InputState.h"
#include "GigaWidget.h"

std::vector<GigaWidget *>widgets_storage;

GigaWidget::GigaWidget() {
    _x = 0; 
    _y = 0;
    _width = 0;
    _height = 0;
    
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

bool GigaWidget::onMouse(int x, int y, skui::InputState state, skui::ModifierKey modifiers ) {
    for( int i=_children.size()-1; i>=0; i-- ) {
        GigaWidget *w = _children[i];
        if( w->hitTest( x, y ) ) {
            if( w->onMouse( x - w->x(), y - w->y(), state, modifiers ) ) {
                return true;
            }
            return false;
        }
    }  

    if( state == skui::InputState::kDown ) {
        if( _movable ) {
            _moving = true;
            _lastX = x;
            _lastY = y;
            return true;
        }
    }
    else if( state == skui::InputState::kMove ) {
        if( _moving ) {
            _x += (x - _lastX);
            _y += (y - _lastY);
            //_lastX = x;
            //_lastY = y;
            return true;
        }
    }
    else if( state == skui::InputState::kUp ) {
        if( _moving ) {
            _moving = false;
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
    _children.push_back( &c );
    return *this;
}

bool GigaWidget::hitTest( int x, int y ) {
    if( (x > _x) && (x <= (_x + _width)) &&
        (y > _y) && (y <= (_y + _height)) ) {
            return true;
    }
    return false;
}