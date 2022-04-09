#include "TemplateLayer.h"

TemplateLayer::TemplateLayer() {}

TemplateLayer::~TemplateLayer() {}

void TemplateLayer::onResize( int w, int h, float scale ) {
    
}
void TemplateLayer::onPaint( SkCanvas& canvas ) {
    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    SkFont font;
    font.setSize(SkIntToScalar(40));

    char message[128] = "";
    sprintf(message, "TemplateLayer");
    canvas.drawSimpleText(
            message, strlen(message), SkTextEncoding::kUTF8, 100, 100, font, paint);
}

bool TemplateLayer::onMouse(int x, int y, skui::InputState, skui::ModifierKey) {
    return false;    
}

bool TemplateLayer::onMouseWheel(float delta, skui::ModifierKey) {
    return false;
}

bool TemplateLayer::onTouch(intptr_t owner, skui::InputState, float x, float y) {
    return false;
}