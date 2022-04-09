#ifndef __SKIA_APP_LAYER_H__
#define __SKIA_APP_LAYER_H__

#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "tools/skui/ModifierKey.h"
#include "tools/skui/InputState.h"
#include "tools/skui/Key.h"
#include "src/utils/SkUTF.h"

class GigaAppLayer {
public:
    GigaAppLayer() : fActive(true), fVisible(true), fCurrentPage(-1) {}
    virtual ~GigaAppLayer() = default;

    bool getActive() { return fActive; }
    void setActive(bool active) { fActive = active; }

    // return value of 'true' means 'I have handled this event'
    virtual void onResize( int w, int h, float scale=1.0 ) {fScaleFactor=scale;}
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

    bool fActive;
    float fScaleFactor;
    bool fVisible;

    int fCurrentPage;

private:
};



#endif