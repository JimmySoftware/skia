#ifndef __GIGA_UI_H__
#define __GIGA_UI_H__

#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "GigaWidget.h"

class GigaUI {
public:
    GigaUI( GigaWidget *root );
    virtual ~GigaUI();

    virtual void draw(SkCanvas &canvas);

    GigaWidget *rootWidget;
};

GigaUI *UI( GigaWidget &root );

#endif //__GIGA_UI_H__