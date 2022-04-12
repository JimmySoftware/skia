#ifndef __GIGA_APP_UI_PAGE_H__
#define __GIGA_APP_UI_PAGE_H__

#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "tools/skui/ModifierKey.h"
#include "tools/skui/InputState.h"
#include "tools/skui/Key.h"
#include "src/utils/SkUTF.h"

class GigaAppPage {
public:
    GigaAppPage() : fActive(false), fVisible(false) {}
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
        SkDebugf( "GigaAppPage::onResize %i %i %0.2f\n", iWidth, iHeight, fScale );
    }
    virtual void onUpdate() {}
    virtual void onPaint(SkCanvas &canvas) {}
    virtual bool onChar(SkUnichar c, skui::ModifierKey) { return false; }
    virtual bool onKey(skui::Key, skui::InputState, skui::ModifierKey) { return false; }
    virtual bool onMouse(int x, int y, skui::InputState, skui::ModifierKey) { return false; }
    virtual bool onMouseWheel(float delta, skui::ModifierKey) { return false; }
    virtual bool onTouch(intptr_t owner, skui::InputState, float x, float y) { return false; }
    virtual void onFontChange() {}

    // Platform-detected gesture events
    virtual bool onFling(skui::InputState state) { return false; }
    virtual bool onPinch(skui::InputState state, float scale, float x, float y) { return false; }
    virtual void onUIStateChanged(const SkString& stateName, const SkString& stateValue) {}

protected:
    bool fActive;
    bool fVisible;

    int iWidth;
    int iHeight;
    float fScale;
};



#endif //__GIGA_APP_UI_PAGE_H__