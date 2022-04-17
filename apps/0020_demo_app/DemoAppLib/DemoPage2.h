#ifndef __DEMO_PAGE2_H__
#define __DEMO_PAGE2_H__

#include "GigaAppPage.h"
#include "include/core/SkColor.h"
#include "include/core/SkFont.h"



class DemoPage2 : public GigaAppPage {
public:
    DemoPage2( );
    virtual ~DemoPage2() override;

    void onPaint( SkCanvas& canvas ) override;

private:
};

#endif //__DEMO_PAGE2_H__