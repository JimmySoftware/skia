#include "DemoPage2.h"
#include "GigaUI.h"

DemoPage2::DemoPage2() {
    UI(Widget().font(Font().Regular("fonts/Kanit-Regular.ttf")
                             .Bold("fonts/Kanit-Bold.ttf")
                             .Italic("fonts/Kanit-Italic.ttf")
                             .BoldItalic("fonts/Kanit-BoldItalic.ttf")
                             .Icon("fonts/Font Awesome 6 Pro-Regular-400.otf"))
               .bounds(50, 100, 640, 480)
               .bg_color(0xFF6495ED)
               ._(Widget().bounds(10, 10, 200, 100)
                          .movable(true)
                          ._(Widget().bounds(10, 10, 100, 80).movable(true))
                          ._(Widget().bounds(120, 10, 100, 80).movable(true)))
               ._(Image("images/ElonMusk.png").posn(10, 120).movable(true))
               ._(Icon(0xf015).size(32).posn(260, 120).border(true))
               ._(Text("สวัสดีชาวโลก เป็ดที่เป่าปี่นี้ดีที่สุด").size(40).posn(10, 274).border(true))
               ._(Widget().bounds(220, 10, 200, 100))
               ._(Widget().bounds(430, 10, 200, 200))
               ._(Text("Hello world...สวัสดีชาวโลกนี้")
                          .BoldItalic()
                          .size(16)
                          .border(true)
                          .posn(430, 220)
                          .movable(true)));
}

DemoPage2::~DemoPage2() {}

void DemoPage2::onPaint(SkCanvas& canvas) {
    canvas.clear(SK_ColorWHITE);

    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    paint.setStyle(SkPaint::Style::kStroke_Style);

    canvas.drawRect(SkRect::MakeXYWH(20, 20, iWidth - 40, iHeight - 40), paint);

    SkFont font;
    font.setSize(SkIntToScalar(40));

    char message[128] = "";
    sprintf(message, "Page 2");
    paint.setStyle(SkPaint::Style::kFill_Style);
    canvas.drawSimpleText(message, strlen(message), SkTextEncoding::kUTF8, 120, 120, font, paint);
}
