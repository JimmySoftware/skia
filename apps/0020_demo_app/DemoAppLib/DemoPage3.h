#ifndef __DEMO_PAGE3_H__
#define __DEMO_PAGE3_H__

#include "GigaAppPage.h"
#include "include/core/SkColor.h"
#include "include/core/SkFont.h"

class DemoPage3 : public GigaAppPage {
public:
    DemoPage3( );
    virtual ~DemoPage3() override;

    void onPaint( SkCanvas& canvas ) override;
    bool onMouse(int x, int y, skui::InputState, skui::ModifierKey) override;
    bool onMouseWheel(float delta, skui::ModifierKey) override;
    bool onTouch(intptr_t owner, skui::InputState, float x, float y) override;

private:
};

#endif //__DEMO_PAGE3_H__