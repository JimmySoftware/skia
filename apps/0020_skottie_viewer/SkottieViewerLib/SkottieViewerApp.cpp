#include "include/core/SkCanvas.h"
#include "include/core/SkFont.h"
#include "include/core/SkColor.h"
#include "include/core/SkGraphics.h"
#include "include/core/SkSurface.h"
#include "include/effects/SkGradientShader.h"
#include "modules/skottie/include/Skottie.h"
#include "modules/skottie/include/SkottieProperty.h"
#include "modules/skottie/utils/SkottieUtils.h"
#include "modules/skresources/include/SkResources.h"
#include "src/core/SkStreamPriv.h"
#include "tools/Resources.h"

#include "SkottieViewerApp.h"

class ResourceProvider final : public skresources::ResourceProvider {
public:
    sk_sp<skresources::ImageAsset> loadImageAsset(const char *resource_path, const char *resource_name,
                                                    const char *resource_id ) const override {
        //printf( "resource: %s %s %s\n", resource_path, resource_name, resource_id );
        char sz[128];
        sprintf( sz, "skottie/%s%s", resource_path, resource_name );
        return skresources::MultiFrameImageAsset::Make(GetResourceAsData(sz));
    }
};

SkottieViewerApp::SkottieViewerApp( ) 
    : fAnimation(nullptr) {

}

SkottieViewerApp::~SkottieViewerApp() {

}

SkottieViewerApp *SkottieViewerApp::createApp() {
    return new SkottieViewerApp();
}

void SkottieViewerApp::setup() {
    const char *skottie_filename = 
        //"skottie/skottie_sample_1.json";
        //"skottie/skottie_sample_2.json";
        //"skottie/skottie-glow-spread.json";
        //"skottie/skottie-outerglow-style.json";
        //"skottie/skottie_sample_multiframe.json";
        
        "skottie/Start.json";
        //"skottie/Shutdown.json";
        //"skottie/Menu.json";
        //"skottie/Charging.json";
        //"skottie/ChargingFast.json";
        //"skottie/ChargingFull.json";
        //"skottie/BatteryEmpty.json";

    if (auto stream = GetResourceAsStream(skottie_filename)) {
        //sk_sp<SkData> data(SkData::MakeFromStream(stream.get(), stream->getLength()));
        //fAnimation = skottie::Animation::Builder()
        //                .setResourceProvider(sk_make_sp<ResourceProvider>())
        //                .make(stream.get());
        //fPropManager = std::make_unique<skottie_utils::CustomPropertyManager>();
        fAnimation   = skottie::Animation::Builder()
                        //.setPropertyObserver(fPropManager->getPropertyObserver())
                        .setResourceProvider(sk_make_sp<ResourceProvider>())
                        .make((SkStream *)stream.get());               
        fAnimation->seek(0);
        printf( "Animation OK\n" );
    }
    fAnimTimer.run();
}

void SkottieViewerApp::draw( SkCanvas &canvas ) {
    canvas.clear(SK_ColorBLACK);
    if ( fAnimation == nullptr ) {
        return;
    }
    
    fAnimTimer.updateTime();
    double nanos = fAnimTimer.nanos();

    const auto duration = fAnimation->duration();
    fAnimation->seek(std::fmod(1e-9 * nanos, duration) / duration);  

    auto dest = SkRect::MakeWH(1024, 600);
    fAnimation->render(&canvas, &dest);  
}
