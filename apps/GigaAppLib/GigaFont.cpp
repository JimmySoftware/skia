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
    for( int i=0; i<FONT_MAX; i++ ) {
        _typeface[i] = nullptr;
    }
}

GigaFont::~GigaFont() {

}

void GigaFont::_Regular( sk_sp<SkData> data ) {
    _typeface[FONT_REGULAR] = SkTypeface::MakeFromData( data );
}

void GigaFont::_Bold( sk_sp<SkData> data ) {
    _typeface[FONT_BOLD] = SkTypeface::MakeFromData( data );
}

void GigaFont::_Italic( sk_sp<SkData> data ) {
    _typeface[FONT_ITALIC] = SkTypeface::MakeFromData( data );
}

void GigaFont::_BoldItalic( sk_sp<SkData> data ) {
    _typeface[FONT_BOLDITALIC] = SkTypeface::MakeFromData( data );
}

void GigaFont::_Icon( sk_sp<SkData> data ) {
    _typeface[FONT_ICON] = SkTypeface::MakeFromData( data );
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

GigaFont &GigaFont::Bold( std::string filename ) {
#ifdef __EMSCRIPTEN__
    emscriptenDownloadAsset( this, filename, 
        [](struct emscripten_fetch_t *fetch) {
            sk_sp<SkData> data = SkData::MakeWithCopy( fetch->data, fetch->numBytes );
            GigaFont *font = (GigaFont *)fetch->userData;
            font->_Bold( data );
        },
        [](struct emscripten_fetch_t *fetch) {
            SkDebugf( "Download failed\n" );
        } 
    );
    return true;
#else    
    sk_sp<SkData> data = GetResourceAsData(filename.c_str());
    _Bold( data );
#endif    
    return *this;
}

GigaFont &GigaFont::Italic( std::string filename ) {
#ifdef __EMSCRIPTEN__
    emscriptenDownloadAsset( this, filename, 
        [](struct emscripten_fetch_t *fetch) {
            sk_sp<SkData> data = SkData::MakeWithCopy( fetch->data, fetch->numBytes );
            GigaFont *font = (GigaFont *)fetch->userData;
            font->_Italic( data );
        },
        [](struct emscripten_fetch_t *fetch) {
            SkDebugf( "Download failed\n" );
        } 
    );
    return true;
#else    
    sk_sp<SkData> data = GetResourceAsData(filename.c_str());
    _Italic( data );
#endif    
    return *this;
}

GigaFont &GigaFont::BoldItalic( std::string filename ) {
#ifdef __EMSCRIPTEN__
    emscriptenDownloadAsset( this, filename, 
        [](struct emscripten_fetch_t *fetch) {
            sk_sp<SkData> data = SkData::MakeWithCopy( fetch->data, fetch->numBytes );
            GigaFont *font = (GigaFont *)fetch->userData;
            font->_BoldItalic( data );
        },
        [](struct emscripten_fetch_t *fetch) {
            SkDebugf( "Download failed\n" );
        } 
    );
    return true;
#else    
    sk_sp<SkData> data = GetResourceAsData(filename.c_str());
    _BoldItalic( data );
#endif    
    return *this;
}

GigaFont &GigaFont::Icon( std::string filename ) {
#ifdef __EMSCRIPTEN__
    emscriptenDownloadAsset( this, filename, 
        [](struct emscripten_fetch_t *fetch) {
            sk_sp<SkData> data = SkData::MakeWithCopy( fetch->data, fetch->numBytes );
            GigaFont *font = (GigaFont *)fetch->userData;
            font->_Icon( data );
        },
        [](struct emscripten_fetch_t *fetch) {
            SkDebugf( "Download failed\n" );
        } 
    );
    return true;
#else    
    sk_sp<SkData> data = GetResourceAsData(filename.c_str());
    _Icon( data );
#endif    
    return *this;
}

