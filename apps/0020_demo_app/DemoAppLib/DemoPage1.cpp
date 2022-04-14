#include "include/core/SkCanvas.h"
#include "include/core/SkFont.h"
#include "include/core/SkColor.h"
#include "include/core/SkGraphics.h"
#include "include/core/SkSurface.h"
#include "include/effects/SkGradientShader.h"
#include "DemoPage1.h"

DemoPage1::DemoPage1()
: fRotationAngle(0) {
}

DemoPage1::~DemoPage1() {}

void DemoPage1::onPaint( SkCanvas& canvas ) {
    canvas.clear(SK_ColorWHITE);
    canvas.save();
    canvas.scale( fScale, fScale );

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
    static const char message[] = "This is DEMO App Page1.";

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

    paint.setColor(SK_ColorBLUE);
    font.setSize(SkIntToScalar(40));
    
    canvas.drawSimpleText( message, strlen(message), SkTextEncoding::kUTF8, 200, 200, font, paint);
    canvas.restore();
}

bool DemoPage1::onMouse(int x, int y, skui::InputState, skui::ModifierKey) {
    return false;    
}

bool DemoPage1::onMouseWheel(float delta, skui::ModifierKey) {
    return false;
}

bool DemoPage1::onTouch(intptr_t owner, skui::InputState, float x, float y) {
    return false;
}