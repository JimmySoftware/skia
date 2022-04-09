#ifndef __HELLOWORLD_LAYER_H__
#define __HELLOWORLD_LAYER_H__

#include "../../GigaAppLib/GigaApp.h"

class DemoApp : public GigaApp {
public:
    DemoApp( );
    virtual ~DemoApp() override;

    static DemoApp *createApp();

    virtual void setup() override;
    virtual void draw( SkCanvas &canvas ) override;
private:
    SkScalar fRotationAngle;      
};

#endif