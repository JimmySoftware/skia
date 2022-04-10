#include "DemoPage2.h"

DemoPage2::DemoPage2() {}

DemoPage2::~DemoPage2() {}

void DemoPage2::onResize( int w, int h, float scale ) {
    
}
void DemoPage2::onPaint( SkCanvas& canvas ) {
    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    SkFont font;
    font.setSize(SkIntToScalar(40));

    char message[128] = "";
    sprintf(message, "DemoPage2");
    canvas.drawSimpleText(
            message, strlen(message), SkTextEncoding::kUTF8, 200, 200, font, paint);
}

bool DemoPage2::onMouse(int x, int y, skui::InputState, skui::ModifierKey) {
    return false;    
}

bool DemoPage2::onMouseWheel(float delta, skui::ModifierKey) {
    return false;
}

bool DemoPage2::onTouch(intptr_t owner, skui::InputState, float x, float y) {
    return false;
}