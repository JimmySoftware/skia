#include "tools/skui/ModifierKey.h"
#include "tools/skui/InputState.h"
#include "GigaUI.h"

extern std::string strDebug;

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

bool GigaUI::onTouch(intptr_t owner, skui::InputState state, float x, float y) {
    char sz[128];
    sprintf( sz, "GigaUI::onTouch %0.2f %0.2f", x, y );
    strDebug = std::string( sz );

    if( rootWidget && rootWidget->hitTest( x, y ) ) {
        rootWidget->onTouch( owner, state, x - rootWidget->x(), y - rootWidget->y() );
    }
    return false;
}