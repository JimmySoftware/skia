#ifndef __GIGA_IMAGE_H__
#define __GIGA_IMAGE_H__

#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "include/core/SkImage.h"
#include "../GigaWidget.h"

class GigaImage : public GigaWidget {
public:    
    GigaImage();
    virtual ~GigaImage() override;

    bool load( const char *filename );
    void setImage( sk_sp<SkImage> img );

protected:
    sk_sp<SkImage> image;

    virtual void _draw_content(SkCanvas &canvas) override;    
};

GigaImage &Image( const char *filename );

#endif //__GIGA_IMAGE_H__