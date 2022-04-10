#ifndef __DEMO_LAYER_H__
#define __DEMO_LAYER_H__

#include "GigaAppLayer.h"
#include "include/core/SkColor.h"
#include "include/core/SkFont.h"

class DemoLayer : public GigaAppLayer {
public:
    DemoLayer( );
    virtual ~DemoLayer() override;

    void onResize( int w, int h, float scale ) override;
    void onPaint( SkCanvas& canvas ) override;
private:
};

#endif //__DEMO_LAYER_H__