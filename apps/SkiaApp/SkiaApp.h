#ifndef SKIA_APP_DEFINED
#define SKIA_APP_DEFINED

#include "src/utils/SkUTF.h"
#include "tools/sk_app/Application.h"
#include "tools/sk_app/Window.h"
#include "tools/skui/ModifierKey.h"

#include "../GigaApp/GigaApp.h"

class SkCanvas;

class SkiaApp : public sk_app::Application, sk_app::Window::Layer {
public:
    SkiaApp(int argc, char** argv, void* platformData, GigaApp *app);
    ~SkiaApp() override;

    void pushLayer(  sk_app::Window::Layer *layer );

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

#endif //SKIA_APP_DEFINED