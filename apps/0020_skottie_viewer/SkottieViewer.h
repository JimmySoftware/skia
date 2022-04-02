/*
* Copyright 2017 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#ifndef SkottieViewerApp_DEFINED
#define SkottieViewerApp_DEFINED

#include "tools/sk_app/Application.h"
#include "tools/sk_app/Window.h"
#include "../GigaApp/GigaApp.h"


class SkCanvas;

class SkottieViewer : public sk_app::Application, sk_app::Window::Layer {
public:
    SkottieViewer(int argc, char** argv, void* platformData);
    ~SkottieViewer() override;

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
