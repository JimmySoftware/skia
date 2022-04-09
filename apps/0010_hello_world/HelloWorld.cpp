/*
* Copyright 2017 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/
#include "tools/sk_app/Application.h"
#include "tools/sk_app/Window.h"
#include "../GigaAppLib/GigaMainApp.h"
#include "HelloWorldLib/HelloWorldApp.h"

using namespace sk_app;



GigaApp *GigaApp::create() {
    return HelloWorldApp::createApp();
}



