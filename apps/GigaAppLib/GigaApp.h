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

    virtual void setup() = 0;
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