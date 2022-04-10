#ifndef __DEMO_PAGE1_H__
#define __DEMO_PAGE1_H__

#include "GigaAppPage.h"
#include "include/core/SkColor.h"
#include "include/core/SkFont.h"

class DemoPage1 : public GigaAppPage {
public:
    DemoPage1( );
    virtual ~DemoPage1() override;

    void onResize( int w, int h, float scale ) override;
    void onPaint( SkCanvas& canvas ) override;
    bool onMouse(int x, int y, skui::InputState, skui::ModifierKey) override;
    bool onMouseWheel(float delta, skui::ModifierKey) override;
    bool onTouch(intptr_t owner, skui::InputState, float x, float y) override;

private:
    SkScalar fRotationAngle;  
};

#endif //__DEMO_PAGE1_H__