/*
* Copyright 2017 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#ifndef GigaMainApp_DEFINED
#define GigaMainApp_DEFINED

#include "include/core/SkCanvas.h"
#include "tools/sk_app/Application.h"
#include "tools/sk_app/Window.h"
#include "tools/skui/ModifierKey.h"
#include "src/utils/SkUTF.h"
#include "GigaApp.h"

class GigaMainApp : public sk_app::Application, sk_app::Window::Layer {
public:
    GigaMainApp(int argc, char** argv, void* platformData);
    ~GigaMainApp() override;

    void onIdle() override;

    void onBackendCreated() override;
    void onPaint(SkSurface*) override;
    bool onChar(SkUnichar c, skui::ModifierKey modifiers) override;

private:
    void updateTitle();

    sk_app::Window* fWindow;
    sk_app::Window::BackendType fBackendType;

    GigaApp *gigaApp;
};

#endif
