#ifndef __DEMO_APP_H__
#define __DEMO_APP_H__

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