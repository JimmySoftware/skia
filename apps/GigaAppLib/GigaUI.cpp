#include "GigaUI.h"

GigaUI::GigaUI( GigaWidget *_root ) {
    rootWidget = _root;
}

GigaUI::~GigaUI() {

}

GigaUI *UI( GigaWidget &root ) {
    return new GigaUI( &root );
}

void GigaUI::draw(SkCanvas &canvas) {
    if( rootWidget ) {
        rootWidget->pre_draw( canvas );
        rootWidget->draw( canvas );
        rootWidget->post_draw( canvas );
    }    
}