#ifndef __GIGA_FONT_H__
#define __GIGA_FONT_H__

#include <vector>
#include <string>
#include "include/core/SkTypeface.h"

class GigaFont {
public:
    GigaFont();
    ~GigaFont();

    GigaFont &Regular( std::string fn );
    GigaFont &Bold( std::string fn );
    GigaFont &Italic( std::string fn );
    GigaFont &BoldItalic( std::string fn );
    GigaFont &Icon( std::string fn );

protected:
    sk_sp<SkTypeface> _tfRegular;
    sk_sp<SkTypeface> _tfBold;
    sk_sp<SkTypeface> _tfItalic;
    sk_sp<SkTypeface> _tfBoldItalic;
    sk_sp<SkTypeface> _tfIcon;
};

GigaFont &Font();

#endif //__GIGA_FONT_H__