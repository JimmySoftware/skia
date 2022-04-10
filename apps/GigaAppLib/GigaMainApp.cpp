#include "GigaMainApp.h"

#include "include/core/SkCanvas.h"
#include "include/core/SkFont.h"
#include "include/core/SkGraphics.h"
#include "include/core/SkSurface.h"
#include "include/effects/SkGradientShader.h"

using namespace sk_app;

Application* Application::Create(int argc, char** argv, void* platformData) {
    return new GigaMainApp(argc, argv, platformData);
}

GigaMainApp::GigaMainApp(int argc, char** argv, void* platformData)
#if defined(SK_GL)
        : fBackendType(Window::kNativeGL_BackendType)
#elif defined(SK_VULKAN)
        : fBackendType(Window::kVulkan_BackendType)
#elif defined(SK_DAWN)
        : fBackendType(Window::kDawn_BackendType)
#else
        : fBackendType(Window::kRaster_BackendType)
#endif
        {
    gigaApp = GigaApp::create();
    SkGraphics::Init();

    fWindow = Window::CreateNativeWindow(platformData);
    fWindow->setRequestedDisplayParams(DisplayParams());

    // register callbacks
    fWindow->pushLayer(this);

    fWindow->attach(fBackendType);
}

GigaMainApp::~GigaMainApp() {
    fWindow->detach();
    delete fWindow;
}

void GigaMainApp::updateTitle() {
    if (!fWindow) {
        return;
    }

    SkString title("Hello World ");
    if (Window::kRaster_BackendType == fBackendType) {
        title.append("Raster");
    } else {
#if defined(SK_GL)
        title.append("GL");
#elif defined(SK_VULKAN)
        title.append("Vulkan");
#elif defined(SK_DAWN)
        title.append("Dawn");
#else
        title.append("Unknown GPU backend");
#endif
    }

    fWindow->setTitle(title.c_str());
}

void GigaMainApp::onBackendCreated() {
    this->updateTitle();

    gigaApp->setup();

    fWindow->show();
    fWindow->inval();
}

void GigaMainApp::onPaint(SkSurface* surface) {
    SkCanvas *canvas = surface->getCanvas();
    gigaApp->draw( *canvas );
    gigaApp->drawLayers( *canvas );
}

void GigaMainApp::onIdle() {
    // Just re-paint continuously
    fWindow->inval();
}

bool GigaMainApp::onKey(skui::Key k, skui::InputState state, skui::ModifierKey modifiers) {
    return gigaApp->onKey( k, state, modifiers );
}

bool GigaMainApp::onChar(SkUnichar c, skui::ModifierKey modifiers) {
    if (' ' == c) {
        if (Window::kRaster_BackendType == fBackendType) {
#if defined(SK_GL)
            fBackendType = Window::kNativeGL_BackendType;
#elif defined(SK_VULKAN)
            fBackendType = Window::kVulkan_BackendType;
#elif defined(SK_DAWN)
            fBackendType = Window::kDawn_BackendType;
#else
            SkDebugf("No GPU backend configured\n");
            return true;
#endif
        } else {
            fBackendType = Window::kRaster_BackendType;
        }
        fWindow->detach();
        fWindow->attach(fBackendType);
    }
    return gigaApp->onChar( c, modifiers );
}
