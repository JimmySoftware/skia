#include "DemoPage2.h"
#include "GigaUI.h"

DemoPage2::DemoPage2() {
    ui = UI( 
        Widget().bounds( 100, 100, 640, 480 ).bg_color( 0xFF6495ED )
            .child( Widget().bounds( 10, 10, 200, 100 )
                .child( Widget().bounds( 10, 10, 100, 80 ) )
             )
            .child( Widget().bounds(220, 10, 200, 100 ) )
            .child( Widget().bounds(430, 10, 200, 200 ) )
    );
}

DemoPage2::~DemoPage2() {}

void DemoPage2::onPaint( SkCanvas& canvas ) {
    canvas.clear(SK_ColorWHITE);

    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    paint.setStyle( SkPaint::Style::kStroke_Style );

    canvas.drawRect( SkRect::MakeXYWH( 20, 20, iWidth-40, iHeight-40 ), paint) ;

    SkFont font;
    font.setSize(SkIntToScalar(40));

    char message[128] = "";
    sprintf(message, "Page 2");
    paint.setStyle( SkPaint::Style::kFill_Style );
    canvas.drawSimpleText(
            message, strlen(message), SkTextEncoding::kUTF8, 120, 120, font, paint);
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