#include <vector>
#include <string>
#include "tools/Resources.h"
#include "GigaFont.h"

std::vector<GigaFont *>font_storage;

GigaFont &Font() {
    GigaFont *_font = new GigaFont();
    font_storage.push_back( _font );
    return *_font; 
}

GigaFont::GigaFont() {
    _tfRegular = nullptr;
    _tfBold = nullptr;
    _tfBoldItalic = nullptr;
    _tfItalic = nullptr;
    _tfIcon= nullptr;
}

GigaFont::~GigaFont() {

}

void GigaFont::_Regular( sk_sp<SkData> data ) {
    _tfRegular = SkTypeface::MakeFromData( data );
}

GigaFont &GigaFont::Regular( std::string filename ) {  
#ifdef __EMSCRIPTEN__
    emscriptenDownloadAsset( this, filename, 
        [](struct emscripten_fetch_t *fetch) {
            sk_sp<SkData> data = SkData::MakeWithCopy( fetch->data, fetch->numBytes );
            GigaFont *font = (GigaFont *)fetch->userData;
            font->_Regular( data );
        },
        [](struct emscripten_fetch_t *fetch) {
            SkDebugf( "Download failed\n" );
        } 
    );
    return true;
#else    
    sk_sp<SkData> data = GetResourceAsData(filename.c_str());
    _Regular( data );
#endif    
    return *this;
}

GigaFont &GigaFont::Bold( std::string fn ) {
    return *this;
}

GigaFont &GigaFont::Italic( std::string fn ) {
    return *this;
}

GigaFont &GigaFont::BoldItalic( std::string fn ) {
    return *this;
}

GigaFont &GigaFont::Icon( std::string fn ) {
    return *this;
}

