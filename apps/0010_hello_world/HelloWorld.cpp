#include "../SkiaApp/SkiaApp.h"
#include "app/HelloWorldApp.h"

using namespace sk_app;

Application* Application::Create(int argc, char** argv, void* platformData) {
    static GigaApp *gigaApp = new HelloWorldApp();
    
    return new SkiaApp(argc, argv, platformData, gigaApp);
}
