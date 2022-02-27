#include "../SkiaApp/SkiaApp.h"
#include "app/SkottieViewerApp.h"

using namespace sk_app;

GigaApp *gigaApp = new SkottieViewerApp();

Application* Application::Create(int argc, char** argv, void* platformData) {
    return new SkiaApp(argc, argv, platformData, gigaApp);
}
