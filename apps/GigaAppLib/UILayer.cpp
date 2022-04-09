#include "UILayer.h"

UILayer::UILayer() {}

UILayer::~UILayer() {}

void UILayer::onResize( int w, int h, float scale ) {
    
}
void UILayer::onPaint( SkCanvas& canvas ) {
    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    SkFont font;
    font.setSize(SkIntToScalar(40));

    char message[128] = "";
    sprintf(message, "UILayer");
    canvas.drawSimpleText(
            message, strlen(message), SkTextEncoding::kUTF8, 200, 200, font, paint);
}

bool UILayer::onMouse(int x, int y, skui::InputState, skui::ModifierKey) {
    return false;    
}

bool UILayer::onMouseWheel(float delta, skui::ModifierKey) {
    return false;
}

bool UILayer::onTouch(intptr_t owner, skui::InputState, float x, float y) {
    return false;
}