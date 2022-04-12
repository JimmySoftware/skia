#include "GigaMainApp.h"

#include "include/core/SkCanvas.h"
#include "include/core/SkFont.h"
#include "include/core/SkGraphics.h"
#include "include/core/SkSurface.h"
#include "include/effects/SkGradientShader.h"


char message1[128] = "";

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
        , iWidth( 0 )
        , iHeight( 0 )
        , fScale( 1.0 )
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

    SkDebugf( "GigaMainApp::onBackendCreated\n" );
    onResize( fWindow->width(), fWindow->height() );
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
    if( fScale != fWindow->scaleFactor() || iWidth != fWindow->width() || iHeight != fWindow->height() ) {
        fWindow->detach();
        fWindow->attach(fBackendType);
        onResize( fWindow->width(), fWindow->height() );
    }     
    fWindow->inval();
}

void GigaMainApp::onResize(int width, int height) {
    iWidth = width;
    iHeight = height;
    fScale = fWindow->scaleFactor();
    SkDebugf( "GigaMainApp::onResize %i %i %0.2f\n", iWidth, iHeight, fScale );

    gigaApp->onResize( width, height, fScale );
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

bool GigaMainApp::onMouse(int x, int y, skui::InputState state, skui::ModifierKey modifiers) { 
    return gigaApp->onMouse( x, y, state, modifiers );
}

bool GigaMainApp::onMouseWheel(float delta, skui::ModifierKey modifiers) { 
    return gigaApp->onMouseWheel( delta, modifiers ); 
}

bool GigaMainApp::onTouch(intptr_t owner, skui::InputState state, float x, float y) { 
    return gigaApp->onTouch( owner, state, x, y ); 
}


bool GigaMainApp::onFling(skui::InputState state) { 
    SkDebugf( "Fling: %i\n", (int)state );
    return gigaApp->onFling( state );
}

bool GigaMainApp::onPinch(skui::InputState state, float scale, float x, float y) { 
    return gigaApp->onPinch( state, scale, x, y );
}