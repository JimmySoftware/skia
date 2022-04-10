#ifndef __GIGA_APP_LAYER_H__
#define __GIGA_APP_LAYER_H__

#include "include/core/SkCanvas.h"
#include "include/private/SkTDArray.h"
#include "GigaAppLayer.h"

class GigaApp {
public:
    GigaApp() {}
    virtual ~GigaApp() {}

    static GigaApp *create();

    void pushLayer(GigaAppLayer* layer) { fLayers.push_back(layer); }

    virtual void setup() {}
    virtual void draw( SkCanvas &canvas ) {}
    virtual bool onChar(SkUnichar c, skui::ModifierKey modifiers) {
        for (int i = 0; i < fLayers.count(); ++i) {
            if( fLayers[i]->getActive() ) {
                if( fLayers[i]->onChar( c, modifiers) ) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool onKey(skui::Key k, skui::InputState state, skui::ModifierKey modifiers) {
        for (int i = 0; i < fLayers.count(); ++i) {
            if( fLayers[i]->getActive() ) {
                if( fLayers[i]->onKey( k, state, modifiers) ) {
                    return true;
                }
            }
        }
        return false;
    } 

    virtual bool onMouse(int x, int y, skui::InputState state, skui::ModifierKey modifiers ) {
        for (int i = fLayers.count()-1; i>=0; --i) {
            if( fLayers[i]->getActive() ) 
            {
                if( fLayers[i]->onMouse( x, y, state, modifiers ) ) {
                    return true;
                }
            }
        }
        return false;  
    }

    virtual bool onMouseWheel(float delta, skui::ModifierKey modifiers) {
        for (int i = fLayers.count()-1; i>=0; --i) {
            if( fLayers[i]->getActive() ) 
            {
                if( fLayers[i]->onMouseWheel( delta, modifiers ) ) {
                    return true;
                }
            }
        }
        return false; 
    }

    virtual bool onTouch(intptr_t owner, skui::InputState state, float x, float y) {
        for (int i = fLayers.count()-1; i>=0; --i) {
            if( fLayers[i]->getActive() ) 
            {
                if( fLayers[i]->onTouch( owner, state, x, y ) ) {
                    return true;
                }
            }
        }
        return false; 
    } 

    virtual bool onFling(skui::InputState state) {
        for (int i = fLayers.count()-1; i>=0; --i) {
            if( fLayers[i]->getActive() ) 
            {
                if( fLayers[i]->onFling( state ) ) {
                    return true;
                }
            }
        }
        return false;        
    }

    virtual bool onPinch(skui::InputState state, float scale, float x, float y) {
        for (int i = fLayers.count()-1; i>=0; --i) {
            if( fLayers[i]->getActive() ) {
                if( fLayers[i]->onPinch( state, scale, x, y ) ) {
                    return true;
                }
            }
        }
        return false;  
    }     

    void drawLayers( SkCanvas &canvas ) {
        for (int i = 0; i < fLayers.count(); ++i) {
            if( fLayers[i]->getActive() ) {
                fLayers[i]->onUpdate();
            }
            if( fLayers[i]->getVisible() ) {
                fLayers[i]->onPaint(canvas);
                fLayers[i]->drawPages(canvas);
            }
        }
    }

protected:
    SkTDArray<GigaAppLayer*>      fLayers;    
};

#endif //__GIGA_APP_LAYER_H__