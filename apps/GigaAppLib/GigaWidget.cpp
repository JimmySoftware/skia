#include "GigaWidget.h"

std::vector<GigaWidget *>widgets_storage;

GigaWidget::GigaWidget() {

}

GigaWidget::~GigaWidget() {

}

GigaWidget &Widget() {
    GigaWidget *w = new GigaWidget();
    widgets_storage.push_back( w );
    return *w;
}

void GigaWidget::draw(SkCanvas &canvas) {
    SkPaint paint;
    paint.setColor(SK_ColorGREEN);
    paint.setStyle( SkPaint::Style::kFill_Style );

    canvas.drawRect( SkRect::MakeXYWH( _x, _y, _width, _height ), paint) ;
}