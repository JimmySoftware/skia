#ifndef __SKOTTIE_VIEWER_APP_H__
#define __SKOTTIE_VIEWER_APP_H__

#include "tools/sk_app/Application.h"
#include "tools/sk_app/Window.h"
#include "tools/viewer/AnimTimer.h"
#include "modules/skottie/include/Skottie.h"
#include "../../GigaApp/GigaApp.h"

class SkottieViewerApp : public GigaApp {
public:
    SkottieViewerApp( );
    virtual ~SkottieViewerApp() override;

    virtual void setup() override;
    virtual void draw( SkCanvas *canvas ) override;
private:
    sk_sp<skottie::Animation> fAnimation;
    AnimTimer              fAnimTimer;
};

#endif //__SKOTTIE_VIEWER_APP_H__