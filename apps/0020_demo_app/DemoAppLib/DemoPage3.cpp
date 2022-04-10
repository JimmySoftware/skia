#include "DemoPage3.h"

DemoPage3::DemoPage3() {}

DemoPage3::~DemoPage3() {}

void DemoPage3::onResize( int w, int h, float scale ) {
    
}
void DemoPage3::onPaint( SkCanvas& canvas ) {
    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    SkFont font;
    font.setSize(SkIntToScalar(40));

    char message[128] = "";
    sprintf(message, "DemoPage3");
    canvas.drawSimpleText(
            message, strlen(message), SkTextEncoding::kUTF8, 200, 200, font, paint);
}

bool DemoPage3::onMouse(int x, int y, skui::InputState, skui::ModifierKey) {
    return false;    
}

bool DemoPage3::onMouseWheel(float delta, skui::ModifierKey) {
    return false;
}

bool DemoPage3::onTouch(intptr_t owner, skui::InputState, float x, float y) {
    return false;
}