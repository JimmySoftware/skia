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
}

GigaWidget::~GigaWidget() {

}

GigaWidget &Widget() {
    GigaWidget *w = new GigaWidget();
    widgets_storage.push_back( w );
    return *w;
}

bool GigaWidget::onMouse(int x, int y, skui::InputState state, skui::ModifierKey modifiers ) {
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

