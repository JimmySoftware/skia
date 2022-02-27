#ifndef __GIGA_APP_H__
#define __GIGA_APP_H__

#include "tools/sk_app/Application.h"
#include "tools/sk_app/Window.h"

class SkCanvas;

class GigaApp {
public:
    GigaApp();
    virtual ~GigaApp();

    virtual void draw( SkCanvas *canvas ) = 0;

};

#endif //__GIGA_APP_H__