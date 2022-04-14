#include "tools/skui/ModifierKey.h"
#include "tools/skui/InputState.h"
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

bool GigaUI::onMouse(int x, int y, skui::InputState state, skui::ModifierKey modifiers ) {
    if( rootWidget && rootWidget->hitTest( x, y ) ) {
        rootWidget->onMouse( x - rootWidget->x(), y - rootWidget->y(), state, modifiers );
    }
    return false;
}