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

extern char message1[128];

class GigaAppLayer {
public:
    GigaAppLayer() : fActive(true), fVisible(true), fCurrentPage(-1) {}
    virtual ~GigaAppLayer() = default;

    bool getActive() { return fActive; }
    void setActive(bool active) { fActive = active; }

    bool getVisible() { return fVisible; }
    void setVisible(bool visible) { fVisible = visible; }    

    // return value of 'true' means 'I have handled this event'
    virtual void onResize(int width, int height, float scale ) {
        iWidth = width;
        iHeight = height;
        fScale = scale;
        SkDebugf( "GigaAppLayer::onResize %i %i %0.2f\n", iWidth, iHeight, fScale );
        for (int i = 0; i < fPages.count(); ++i ) {
            SkDebugf( "Call %i\n", i );
            fPages[i]->onResize( width, height, scale );
        }        
    }
    virtual void onUpdate() {}
    virtual void onPaint(SkCanvas &canvas) {}
    virtual bool onChar(SkUnichar c, skui::ModifierKey modifiers) {
        int pg = getCurrentPageIndex();
        if( c == 63234 ) {
            previousPage();
            return true;
        }
        else if( c == 63235 ) {
            nextPage();
            return true;
        }
        if( pg >= 0 && pg <fPages.count() ) {
            if( fPages[pg]->onChar( c, modifiers) ) {
                return true;
            }
        }
        return false;
    }
    virtual bool onKey(skui::Key k, skui::InputState state, skui::ModifierKey modifiers) {
        int pg = getCurrentPageIndex();
        if( pg >= 0 && pg <fPages.count() ) {
            if( fPages[pg]->onKey( k, state, modifiers) ) {
                return true;
            }
        }
        return false;
    } 
    virtual bool onMouse(int x, int y, skui::InputState state, skui::ModifierKey modifiers) { 
        SkDebugf( "Touch %i %i \n", x, y );
        if( state == skui::InputState::kDown ) {
            nextPage();
        }
        return false; 
    }
    virtual bool onMouseWheel(float delta, skui::ModifierKey) { return false; }
    virtual bool onTouch(intptr_t owner, skui::InputState state, float x, float y) { 
        SkDebugf( "Touch %0.2f %0.2f\n", x, y );
        if( state == skui::InputState::kDown ) {
            nextPage();
        }
        return false; 
    }
    virtual void onFontChange() {}

    // Platform-detected gesture events
    virtual bool onFling(skui::InputState state) { 
        int pg = getCurrentPageIndex();
        
        sprintf(message1, "Fling  %i %i %i %i", pg, (int)fCurrentPage, fPages.count(), state);
        if( (int)state == 4 ) {
            nextPage();
            //sprintf(message1, "Fling Left1 %i %i %i %i", pg, (int)fCurrentPage, fPages.count(), state);
            //return true;
        }
        else if( (int)state == 3 ) {
            previousPage();
            //sprintf(message1, "Fling Right1 %i %i %i %i", pg, (int)fCurrentPage, fPages.count(), state);
            //return true;
        }
        /*        
        if( pg >= 0 && pg <fPages.count() ) {
            if( fPages[pg]->onFling( state ) ) {
                return true;
            }
        }      
        */  
        return false; 
    }
    virtual bool onPinch(skui::InputState state, float scale, float x, float y) { 
        int pg = getCurrentPageIndex();
        if( pg >= 0 && pg <fPages.count() ) {
            if( fPages[pg]->onPinch( state, scale, x, y ) ) {
                return true;
            }
        }         
        return false; 
    }
    virtual void onUIStateChanged(const SkString& stateName, const SkString& stateValue) {}

    void pushPage(GigaAppPage* page) { fPages.push_back(page); }
    
    int getCurrentPageIndex() { return fCurrentPage; }
    int setCurrentPageIndex( int pg ) {
        if( fCurrentPage >= 0 && fCurrentPage < fPages.count() ) {
            fPages[fCurrentPage]->setVisible( false );
            fPages[fCurrentPage]->setActive( false );
            fCurrentPage = -1;
        }
        if( (pg >= 0) && (pg < fPages.count()) ) 
        {
            fCurrentPage = pg;
            fPages[fCurrentPage]->setActive( true );
            fPages[fCurrentPage]->setVisible( true );
            //sprintf(message1, "Current Page %i %i %i", pg, (int)fCurrentPage, fPages.count());
        }
        else {
            sprintf(message1, "PG Page %i %i %i", pg, (int)fCurrentPage, fPages.count());
        }
        return fCurrentPage;
    }

    void previousPage() {
        int n = fCurrentPage - 1;
        if( n < 0 ) {
            n = fPages.count() - 1;
        }
        setCurrentPageIndex( n );
        sprintf(message1, "Prev1 Page %i %i %i", n, (int)fCurrentPage, fPages.count());
    }

    void nextPage() {
        int n = fCurrentPage + 1;
        if( n >= fPages.count() ) {
            n = 0;
        }
        setCurrentPageIndex( n );
        sprintf(message1, "Next Page %i %i %i", n, (int)fCurrentPage, fPages.count());
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

    int iWidth;
    int iHeight;
    float fScale;
    
    int fCurrentPage;       
};



#endif