/*
* Copyright 2017 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#include "SkiaApp.h"

#include "include/core/SkCanvas.h"
#include "include/core/SkFont.h"
#include "include/core/SkGraphics.h"
#include "include/core/SkSurface.h"
#include "include/effects/SkGradientShader.h"

using namespace sk_app;

SkiaApp::SkiaApp(int argc, char** argv, void* platformData, GigaApp *app)
        : fBackendType(Window::kNativeGL_BackendType)
        , gigaApp(app) {
    SkGraphics::Init();

    fWindow = Window::CreateNativeWindow(platformData);
    fWindow->setRequestedDisplayParams(DisplayParams());

    // register callbacks
    fWindow->pushLayer(this);

    fWindow->attach(fBackendType);

}

SkiaApp::~SkiaApp() {
    fWindow->detach();
    delete fWindow;
}

void SkiaApp::updateTitle() {
    if (!fWindow || fWindow->sampleCount() <= 1) {
        return;
    }

    SkString title("Hello World App!");
    title.append(Window::kRaster_BackendType == fBackendType ? "Raster" : "OpenGL");
    fWindow->setTitle(title.c_str());
}

void SkiaApp::onBackendCreated() {
    this->updateTitle();
    fWindow->show();
    fWindow->inval();
}

void SkiaApp::onPaint(SkSurface* surface) {
    SkCanvas *canvas = surface->getCanvas();

    gigaApp->draw( canvas );
}

void SkiaApp::onIdle() {
    // Just re-paint continuously
    fWindow->inval();
}

bool SkiaApp::onChar(SkUnichar c, skui::ModifierKey modifiers) {
    if (' ' == c) {
        fBackendType = Window::kRaster_BackendType == fBackendType ? Window::kNativeGL_BackendType
                                                                   : Window::kRaster_BackendType;
        fWindow->detach();
        fWindow->attach(fBackendType);
    }
    return true;
}
