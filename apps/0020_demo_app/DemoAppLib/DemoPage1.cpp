#include "DemoPage1.h"

DemoPage1::DemoPage1() {}

DemoPage1::~DemoPage1() {}

void DemoPage1::onResize( int w, int h, float scale ) {
    
}
void DemoPage1::onPaint( SkCanvas& canvas ) {
    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    SkFont font;
    font.setSize(SkIntToScalar(40));

    char message[128] = "";
    sprintf(message, "DemoPage1");
    canvas.drawSimpleText(
            message, strlen(message), SkTextEncoding::kUTF8, 200, 200, font, paint);
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