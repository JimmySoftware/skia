/*
* Copyright 2022 Art & Technology Co.,Ltd.
*
*/
#include "../GigaAppLib/GigaMainApp.h"
#include "HelloWorldLib/HelloWorldApp.h"



GigaApp *GigaApp::create() {
    return HelloWorldApp::createApp();
}



