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
    bool onKey(skui::Key k, skui::InputState state, skui::ModifierKey modifiers) override;
    bool onMouse(int x, int y, skui::InputState, skui::ModifierKey) override;
    bool onMouseWheel(float delta, skui::ModifierKey) override;
    bool onTouch(intptr_t owner, skui::InputState, float x, float y) override;
    bool onFling(skui::InputState state) override;
    bool onPinch(skui::InputState state, float scale, float x, float y) override;    

private:
    void updateTitle();

    sk_app::Window* fWindow;
    sk_app::Window::BackendType fBackendType;

    GigaApp *gigaApp;
};

#endif
