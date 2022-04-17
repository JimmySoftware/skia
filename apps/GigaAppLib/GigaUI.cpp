#include "tools/skui/ModifierKey.h"
#include "tools/skui/InputState.h"
#include "GigaUI.h"

extern std::string strDebug;
std::vector<GigaUI *>ui_storage;

GigaUI::GigaUI() {
    captureMouseWidget = NULL;
    rootWidget = NULL;
}

GigaUI::GigaUI( GigaWidget &_root ) {
    captureMouseWidget = NULL;
    root( _root );
}

GigaUI::~GigaUI() {

}

GigaUI &createUI() {
    GigaUI *_ui = new GigaUI();
    ui_storage.push_back( _ui );
    return *_ui; 
} 

void GigaUI::draw(SkCanvas &canvas) {
    if( rootWidget ) {
        rootWidget->pre_draw( canvas );
        rootWidget->draw( canvas );
        rootWidget->post_draw( canvas );
    }    
}

GigaUI &GigaUI::root( GigaWidget &root ) {
    rootWidget = &root;
    root.ui(this);
    return *this;
}

bool GigaUI::onMouse(int x, int y, skui::InputState state, skui::ModifierKey modifiers ) {
    if( captureMouseWidget ) {
        captureMouseWidget->onMouse( x - captureMouseWidget->ax(), y - captureMouseWidget->ay(), state, modifiers );
    }
    else if( rootWidget && rootWidget->hitTest( x, y ) ) {
        rootWidget->onMouse( x - rootWidget->x(), y - rootWidget->y(), state, modifiers );
    }
    return false;
}

bool GigaUI::onTouch(intptr_t owner, skui::InputState state, float x, float y) {
    if( captureMouseWidget ) {
        captureMouseWidget->onTouch( owner, state, x - captureMouseWidget->ax(), y - captureMouseWidget->ay() );
    }
    else if( rootWidget && rootWidget->hitTest( x, y ) ) {
        rootWidget->onTouch( owner, state, x - rootWidget->x(), y - rootWidget->y() );
    }
    return false;
}