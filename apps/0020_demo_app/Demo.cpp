/*
* Copyright 2022 Art & Technology Co.,Ltd.
*
*/
#include "../GigaAppLib/GigaMainApp.h"
#include "DemoAppLib/DemoApp.h"

GigaApp *GigaApp::create() {
    return DemoApp::createApp();
}



