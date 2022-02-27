/*
* Copyright 2017 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#ifndef HelloWorld_LIB_DEFINED
#define HelloWorld_LIB_DEFINED

#include "../../GigaApp/GigaApp.h"

class HelloWorldApp : public GigaApp {
public:
    HelloWorldApp();
    virtual ~HelloWorldApp() override;

    virtual void draw( SkCanvas *canvas ) override;

private:
    SkScalar fRotationAngle;    
};

#endif // HelloWorld_LIB_DEFINED
