#include "tools/Resources.h"
#include "GigaImage.h"

GigaImage::GigaImage() {

}

GigaImage::~GigaImage() {

}

void GigaImage::setImage( sk_sp<SkImage> img ) {
    image = img;

    if (this->image) {
        _width = this->image->width();
        _height = this->image->height();
        _ow = _width;
        _oh = _height;
        SkDebugf( "Loaded image %i %i\n", _ow, _oh );
    }
}

bool GigaImage::load( const char *filename ) {
    sk_sp<SkImage> img = SkImage::MakeFromEncoded(GetResourceAsData(filename), std::nullopt);
    if( !img ) {
        return false;
    }
    setImage(img);
    return true;
}

GigaImage &Image( const char *filename ) {
    GigaImage *w = new GigaImage();
    w->load( filename );
    widgets_storage.push_back( w );
    return *w;
}

void GigaImage::_draw_content(SkCanvas &canvas) {
    if( image ) {
        SkPaint paint;
        paint.setAntiAlias(true);
        //if( filterColor || changeColorByValue )
        //    paint.setColorFilter(SkColorFilters::Blend(color, SkBlendMode::kSrcATop));

        canvas.drawImage(image, (_width - image->width()) / 2, (_height - image->height()) / 2, 
            SkSamplingOptions(), &paint);
    }
}