#include "tools/Resources.h"
#include "GigaImage.h"
#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#include "emscripten/fetch.h"
#endif

GigaImage::GigaImage() {

}

GigaImage::~GigaImage() {

}

bool GigaImage::setImage( sk_sp<SkImage> img ) {
    image = img;

    if (this->image) {
        _width = this->image->width();
        _height = this->image->height();
        _ow = _width;
        _oh = _height;
        SkDebugf( "Loaded image %i %i\n", _ow, _oh );
        return true;
    }
    return false;
}

bool GigaImage::setData( sk_sp<SkData> data ) {
    sk_sp<SkImage> img = SkImage::MakeFromEncoded( data, std::nullopt );
    if( !img ) {
        return false;
    }
    return setImage(img);
}

bool GigaImage::load( const char *filename ) {
#ifdef __EMSCRIPTEN__
    emscriptenDownloadAsset( this, filename, 
        [](struct emscripten_fetch_t *fetch) {
            sk_sp<SkData> data = SkData::MakeWithCopy( fetch->data, fetch->numBytes );
            GigaImage *widget = (GigaImage *)fetch->userData;
            widget->setData( data );
        },
        [](struct emscripten_fetch_t *fetch) {
            SkDebugf( "Download failed\n" );
        } 
    );
    return true;
#else    
    sk_sp<SkData> data = GetResourceAsData(filename);
    return setData( data );
#endif
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