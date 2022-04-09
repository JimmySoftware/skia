/*
* Copyright 2017 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#include "../GigaAppLib/GigaMainApp.h"
#include "HelloWorldLib/HelloWorldApp.h"

GigaApp *GigaApp::create() {
    return HelloWorldApp::createApp();
}



