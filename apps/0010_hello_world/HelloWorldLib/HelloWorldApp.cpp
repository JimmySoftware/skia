#include "include/core/SkCanvas.h"
#include "include/core/SkFont.h"
#include "include/core/SkColor.h"
#include "include/core/SkGraphics.h"
#include "include/core/SkSurface.h"
#include "include/effects/SkGradientShader.h"
#include "../../GigaAppLib/FPSLayer.h"
#include "HelloWorldApp.h"

HelloWorldApp::HelloWorldApp( ) 
    : fRotationAngle(0) {

}

HelloWorldApp::~HelloWorldApp() {

}

HelloWorldApp *HelloWorldApp::createApp() {
    HelloWorldApp *app = new HelloWorldApp();
    
    app->pushLayer( new FPSLayer(SK_ColorBLACK, true) );

    return app;
}

void HelloWorldApp::setup() {

    try
    {
        SkDebugf( "Try\n" );
        throw std::invalid_argument("HELLO");
    }
    catch(const std::exception& e)
    {
        SkDebugf( "%s\n", e.what() );
    }

}

void HelloWorldApp::draw( SkCanvas &canvas ) {
    GigaApp::draw( canvas );

    // Clear background
    canvas.clear(SK_ColorWHITE);

    SkPaint paint;
    paint.setColor(SK_ColorRED);

    // Draw a rectangle with red paint
    SkRect rect = SkRect::MakeXYWH(10, 10, 128, 128);
    canvas.drawRect(rect, paint);

    // Set up a linear gradient and draw a circle
    {
        SkPoint linearPoints[] = { { 0, 0 }, { 300, 300 } };
        SkColor linearColors[] = { SK_ColorGREEN, SK_ColorBLACK };
        paint.setShader(SkGradientShader::MakeLinear(linearPoints, linearColors, nullptr, 2,
                                                     SkTileMode::kMirror));
        paint.setAntiAlias(true);

        canvas.drawCircle(200, 200, 64, paint);

        // Detach shader
        paint.setShader(nullptr);
    }

    // Draw a message with a nice black paint
    SkFont font;
    font.setSubpixel(true);
    font.setSize(20);
    paint.setColor(SK_ColorBLACK);

    canvas.save();
    static const char message[] = "Hello World App! HELLO......YO!";

    // Translate and rotate
    canvas.translate(300, 300); 
    fRotationAngle += 0.2f;
    if (fRotationAngle > 360) {
        fRotationAngle -= 360;
    }
    canvas.rotate(fRotationAngle);

    // Draw the text
    canvas.drawSimpleText(message, strlen(message), SkTextEncoding::kUTF8, 0, 0, font, paint);

    canvas.restore();   
}
