#include "include/core/SkCanvas.h"
#include "include/core/SkFont.h"
#include "include/core/SkColor.h"
#include "include/core/SkGraphics.h"
#include "include/core/SkSurface.h"
#include "include/effects/SkGradientShader.h"
#include "../../GigaAppLib/FPSLayer.h"
#include "../../GigaAppLib/TemplateLayer.h"
#include "DemoApp.h"
#include "DemoLayer.h"

char message1[128] = "";

DemoApp *DemoApp::createApp() {
    DemoApp *app = new DemoApp();
    
    app->pushLayer( new DemoLayer() );
    app->pushLayer( new FPSLayer(SK_ColorBLACK, true) );

    return app;
}