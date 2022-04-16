#ifndef __GIGA_UI_H__
#define __GIGA_UI_H__

#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "GigaWidget.h"
#include "Widgets/GigaImage.h"

class GigaWidget;

class GigaUI {
public:
    GigaUI( GigaWidget *root );
    virtual ~GigaUI();

    virtual void draw(SkCanvas &canvas);
    virtual bool onMouse(int x, int y, skui::InputState, skui::ModifierKey);
    virtual bool onTouch(intptr_t owner, skui::InputState state, float x, float y);

    void captureMouse( GigaWidget *widget ) { captureMouseWidget = widget; }
    void releaseMouse() { captureMouseWidget = NULL; }

    GigaWidget *rootWidget;

    GigaWidget *captureMouseWidget;
};

GigaUI *UI( GigaWidget &root );

#endif //__GIGA_UI_H__