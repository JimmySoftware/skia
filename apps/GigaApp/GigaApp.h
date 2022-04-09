#ifndef __GIGA_APP_LAYER_H__
#define __GIGA_APP_LAYER_H__

#include "tools/sk_app/Application.h"
#include "tools/sk_app/Window.h"
#include "include/core/SkCanvas.h"
#include "include/private/SkTDArray.h"
#include "GigaAppLayer.h"

class GigaApp {
public:
    GigaApp() {}
    virtual ~GigaApp() {}

    void pushLayer(GigaAppLayer* layer) { fLayers.push_back(layer); }

    virtual void setup() = 0;
    virtual void draw( SkCanvas &canvas ) {}

    void drawLayers( SkCanvas &canvas ) {
        for (int i = 0; i < fLayers.count(); ++i) {
            fLayers[i]->onUpdate();
            fLayers[i]->onPaint(canvas);
        }
    }
protected:
    SkTDArray<GigaAppLayer*>      fLayers;    
};

#endif //__GIGA_APP_LAYER_H__