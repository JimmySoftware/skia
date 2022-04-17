#ifndef __GIGA_UI_H__
#define __GIGA_UI_H__

#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "GigaWidget.h"
#include "GigaFont.h"
#include "Widgets/GigaImage.h"

class GigaWidget;

class GigaUI {
public:
    GigaUI();
    GigaUI(GigaWidget &root);
    virtual ~GigaUI();

    virtual void draw(SkCanvas &canvas);
    virtual bool onMouse(int x, int y, skui::InputState, skui::ModifierKey);
    virtual bool onTouch(intptr_t owner, skui::InputState state, float x, float y);

    void captureMouse( GigaWidget *widget ) { captureMouseWidget = widget; }
    void releaseMouse() { captureMouseWidget = NULL; }

    GigaUI &root( GigaWidget &root ) {
        rootWidget = &root;
        root.ui(this);
        return *this;
    }
    GigaUI &font( GigaFont &_font ) {
        return *this;
    }

    GigaWidget *rootWidget;

    GigaWidget *captureMouseWidget;
};

GigaUI &createUI();

#endif //__GIGA_UI_H__