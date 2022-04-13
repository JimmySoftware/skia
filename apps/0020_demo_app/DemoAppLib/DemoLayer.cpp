#include "DemoLayer.h"
#include "DemoPage1.h"
#include "DemoPage2.h"
#include "DemoPage3.h"

DemoLayer::DemoLayer() {
    pushPage( new DemoPage1() );
    pushPage( new DemoPage2() );
    pushPage( new DemoPage3() );

    setCurrentPageIndex( 0 );
}

DemoLayer::~DemoLayer() {}