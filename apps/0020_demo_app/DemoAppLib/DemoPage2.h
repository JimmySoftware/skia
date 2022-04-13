#ifndef __DEMO_PAGE2_H__
#define __DEMO_PAGE2_H__

#include "GigaAppPage.h"
#include "include/core/SkColor.h"
#include "include/core/SkFont.h"

struct {
  enum { hbox }; 
  const char* my_label = "foo";
  const char* other_label = "bar";
} ui;

class DemoPage2 : public GigaAppPage {
public:
    DemoPage2( );
    virtual ~DemoPage2() override;

    void onPaint( SkCanvas& canvas ) override;
    bool onMouse(int x, int y, skui::InputState, skui::ModifierKey) override;
    bool onMouseWheel(float delta, skui::ModifierKey) override;
    bool onTouch(intptr_t owner, skui::InputState, float x, float y) override;

private:
};

#endif //__DEMO_PAGE2_H__