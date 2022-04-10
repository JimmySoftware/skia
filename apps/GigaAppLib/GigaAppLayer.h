#ifndef __SKIA_APP_LAYER_H__
#define __SKIA_APP_LAYER_H__

#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "tools/skui/ModifierKey.h"
#include "tools/skui/InputState.h"
#include "tools/skui/Key.h"
#include "src/utils/SkUTF.h"
#include "include/private/SkTDArray.h"
#include "GigaAppPage.h"

class GigaAppLayer {
public:
    GigaAppLayer() : fActive(true), fVisible(true), fCurrentPage(-1) {}
    virtual ~GigaAppLayer() = default;

    bool getActive() { return fActive; }
    void setActive(bool active) { fActive = active; }

    bool getVisible() { return fVisible; }
    void setVisible(bool visible) { fVisible = visible; }    

    // return value of 'true' means 'I have handled this event'
    virtual void onResize( int w, int h, float scale=1.0 ) {fScaleFactor=scale;}
    virtual void onUpdate() {}
    virtual void onPaint(SkCanvas &canvas) {}
    virtual bool onChar(SkUnichar c, skui::ModifierKey modifiers) {
        int pg = getCurrentPageIndex();
        if( pg >= 0 && pg <fPages.count() ) {
            if( fPages[pg]->onChar( c, modifiers) ) {
                return true;
            }
        }
        return false;
    }
    virtual bool onKey(skui::Key k, skui::InputState state, skui::ModifierKey modifiers) {
        int pg = getCurrentPageIndex();
        if( k == skui::Key::kLeft ) {
            if( state == skui::InputState::kDown ) {
                SkDebugf( "Left\n" );
            }
        }
        if( k == skui::Key::kRight ) {
            if( state == skui::InputState::kDown ) {
                SkDebugf( "Right\n" );
            }
        }
        if( pg >= 0 && pg <fPages.count() ) {
            if( fPages[pg]->onKey( k, state, modifiers) ) {
                return true;
            }
        }
        return false;
    } 
    virtual bool onMouse(int x, int y, skui::InputState, skui::ModifierKey) { return false; }
    virtual bool onMouseWheel(float delta, skui::ModifierKey) { return false; }
    virtual bool onTouch(intptr_t owner, skui::InputState, float x, float y) { return false; }
    virtual void onFontChange() {}

    // Platform-detected gesture events
    virtual bool onFling(skui::InputState state) { return false; }
    virtual bool onPinch(skui::InputState state, float scale, float x, float y) { return false; }
    virtual void onUIStateChanged(const SkString& stateName, const SkString& stateValue) {}

    void pushPage(GigaAppPage* page) { fPages.push_back(page); }
    
    int getCurrentPageIndex() { return fCurrentPage; }
    int setCurrentPageIndex( int pg ) {
        if( fCurrentPage >= 0 && fCurrentPage < fPages.count() ) {
            fPages[fCurrentPage]->setVisible( false );
            fPages[fCurrentPage]->setActive( false );
            fCurrentPage = -1;
        }
        if( pg >= 0 && pg < fPages.count() ) {
            fCurrentPage = pg;
            fPages[fCurrentPage]->setActive( true );
            fPages[fCurrentPage]->setVisible( true );
        }
        return fCurrentPage;
    }

    void drawPages( SkCanvas &canvas ) {
        for (int i = 0; i < fPages.count(); ++i ) {
            if( fPages[i]->getActive() ) {
                fPages[i]->onUpdate();
            }
            if( fPages[i]->getVisible() ) {
                fPages[i]->onPaint(canvas);
            }
        }
    }    

protected:
    SkTDArray<GigaAppPage*>      fPages; 
    
    bool fActive;
    bool fVisible;
    float fScaleFactor;
    
    int fCurrentPage;       
};



#endif