#ifndef __GIGA_FONT_H__
#define __GIGA_FONT_H__

#include <vector>
#include <string>
#include "include/core/SkTypeface.h"
#include "include/core/SkFont.h"

const int FONT_REGULAR = 0;
const int FONT_BOLD = 1;
const int FONT_ITALIC = 2;
const int FONT_BOLDITALIC = 3;
const int FONT_ICON = 4;

class GigaFont {
public:
    GigaFont();
    ~GigaFont();

    GigaFont &Regular( std::string fn );
    GigaFont &Bold( std::string fn );
    GigaFont &Italic( std::string fn );
    GigaFont &BoldItalic( std::string fn );
    GigaFont &Icon( std::string fn );

    sk_sp<SkTypeface>Regular() { return _tfRegular; }
    sk_sp<SkTypeface>Bold() { return _tfBold; }
    sk_sp<SkTypeface>Italic() { return _tfItalic; }
    sk_sp<SkTypeface>BoldItalic() { return _tfBoldItalic; }
    sk_sp<SkTypeface>Icon() { return _tfIcon; }

    void _Regular( sk_sp<SkData> data );
    void _Bold( sk_sp<SkData> data );
    void _Italic( sk_sp<SkData> data );
    void _BoldItalic( sk_sp<SkData> data );
    void _Icon( sk_sp<SkData> data );

    SkFont *make( const int t, int size );

protected:
    sk_sp<SkTypeface> _tfRegular;
    sk_sp<SkTypeface> _tfBold;
    sk_sp<SkTypeface> _tfItalic;
    sk_sp<SkTypeface> _tfBoldItalic;
    sk_sp<SkTypeface> _tfIcon;
};

GigaFont &Font();

#endif //__GIGA_FONT_H__