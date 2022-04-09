#ifndef __HELLOWORLD_LAYER_H__
#define __HELLOWORLD_LAYER_H__

#include "../../GigaAppLib/GigaApp.h"

class HelloWorldApp : public GigaApp {
public:
    HelloWorldApp( );
    virtual ~HelloWorldApp() override;

    static HelloWorldApp *createApp();

    virtual void setup() override;
    virtual void draw( SkCanvas &canvas ) override;
private:
    SkScalar fRotationAngle;      
};

#endif