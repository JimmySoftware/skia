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
const int FONT_MAX = 5;

class GigaFont {
public:
    GigaFont();
    ~GigaFont();

    GigaFont &Regular( std::string fn );
    GigaFont &Bold( std::string fn );
    GigaFont &Italic( std::string fn );
    GigaFont &BoldItalic( std::string fn );
    GigaFont &Icon( std::string fn );

    void _Regular( sk_sp<SkData> data );
    void _Bold( sk_sp<SkData> data );
    void _Italic( sk_sp<SkData> data );
    void _BoldItalic( sk_sp<SkData> data );
    void _Icon( sk_sp<SkData> data );

    sk_sp<SkTypeface> typeface( int n ) { return _typeface[n]; }

protected:
    sk_sp<SkTypeface> _typeface[5];
};

GigaFont &Font();

#endif //__GIGA_FONT_H__