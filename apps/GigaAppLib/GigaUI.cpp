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
        rootWidget->draw( canvas );
    }    
}