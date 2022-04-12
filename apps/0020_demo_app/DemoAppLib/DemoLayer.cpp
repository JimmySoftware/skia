#include "DemoLayer.h"
#include "DemoPage1.h"
#include "DemoPage2.h"
#include "DemoPage3.h"

DemoLayer::DemoLayer() {
    pushPage( new DemoPage1() );
    pushPage( new DemoPage2() );
    pushPage( new DemoPage3() );

    setCurrentPageIndex( 0 );
}

DemoLayer::~DemoLayer() {}

void DemoLayer::onPaint( SkCanvas& canvas ) {
    // Clear background
    canvas.clear(SK_ColorWHITE);

    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    SkFont font;
    font.setSize(SkIntToScalar(40));

    char message[128] = "";
    sprintf(message, "DemoLayer");
    canvas.drawSimpleText(
            message, strlen(message), SkTextEncoding::kUTF8, 100, 100, font, paint);
}