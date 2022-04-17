#include <vector>
#include <string>
#include "GigaFont.h"

std::vector<GigaFont *>font_storage;

GigaFont &Font() {
    GigaFont *_font = new GigaFont();
    font_storage.push_back( _font );
    return *_font; 
}

GigaFont::GigaFont() {

}

GigaFont::~GigaFont() {

}

GigaFont &GigaFont::Regular( std::string fn ) {  
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

