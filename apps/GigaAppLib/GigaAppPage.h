#ifndef __GIGA_APP_UI_PAGE_H__
#define __GIGA_APP_UI_PAGE_H__

#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "tools/skui/ModifierKey.h"
#include "tools/skui/InputState.h"
#include "tools/skui/Key.h"
#include "src/utils/SkUTF.h"
#include "GigaUI.h"

extern std::string strDebug;

class GigaAppPage {
public:
    GigaAppPage() : fActive(false), fVisible(false) {
        _ui = NULL;
    }
    virtual ~GigaAppPage() = default;

    bool getActive() { return fActive; }
    void setActive(bool active) { fActive = active; }

    bool getVisible() { return fVisible; }
    void setVisible(bool visible) { fVisible = visible; }

    // return value of 'true' means 'I have handled this event'
    virtual void onResize(int width, int height, float scale ) {
        iWidth = width;
        iHeight = height;
        fScale = scale;
    }
    virtual void onUpdate() {}
    virtual void onPaint(SkCanvas &canvas) {}
    virtual bool onChar(SkUnichar c, skui::ModifierKey) { return false; }
    virtual bool onKey(skui::Key, skui::InputState, skui::ModifierKey) { return false; }
    virtual bool onMouse(int x, int y, skui::InputState state, skui::ModifierKey modifiers ) { 
        if( _ui ) {
            if( _ui->onMouse( x / fScale, y / fScale, state, modifiers ) ) {
                return true;
            }
        }
        return false; 
    }
    virtual bool onMouseWheel(float delta, skui::ModifierKey) { return false; }
    virtual bool onTouch(intptr_t owner, skui::InputState state, float x, float y) { 
        if( _ui ) {
            if( _ui->onTouch( owner, state, x / fScale, y / fScale ) ) {
                return true;
            }
        }        
        return false; 
    }
    virtual void onFontChange() {}

    // Platform-detected gesture events
    virtual bool onFling(skui::InputState state) { return false; }
    virtual bool onPinch(skui::InputState state, float scale, float x, float y) { return false; }
    virtual void onUIStateChanged(const SkString& stateName, const SkString& stateValue) {}

    void drawUI(SkCanvas &canvas) {
        if( _ui ) {
            canvas.save();
            canvas.scale( fScale, fScale );
            _ui->draw(canvas);
            canvas.restore();
        }
    }
    GigaUI &UI( GigaWidget &w ) {
        _ui = &createUI( );
        _ui->root(w);
        return *_ui;
    }
protected:
    GigaUI *_ui;
    bool fActive;
    bool fVisible;

    int iWidth;
    int iHeight;
    float fScale;
};



#endif //__GIGA_APP_UI_PAGE_H__