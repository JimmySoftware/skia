#include "../SkiaApp/SkiaApp.h"
#include "app/HelloWorldApp.h"

using namespace sk_app;

GigaApp *gigaApp = new HelloWorldApp();

Application* Application::Create(int argc, char** argv, void* platformData) {
    return new SkiaApp(argc, argv, platformData, gigaApp);
}
