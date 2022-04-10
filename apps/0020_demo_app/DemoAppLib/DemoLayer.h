#ifndef __DEMO_LAYER_H__
#define __DEMO_LAYER_H__

#include "GigaAppLayer.h"
#include "include/core/SkColor.h"
#include "include/core/SkFont.h"

class DemoLayer : public GigaAppLayer {
public:
    DemoLayer( );
    virtual ~DemoLayer() override;

    void onResize( int w, int h, float scale ) override;
    void onPaint( SkCanvas& canvas ) override;
    bool onMouse(int x, int y, skui::InputState, skui::ModifierKey) override;
    bool onMouseWheel(float delta, skui::ModifierKey) override;
    bool onTouch(intptr_t owner, skui::InputState, float x, float y) override;

private:
};

#endif //__DEMO_LAYER_H__