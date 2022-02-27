#include "include/core/SkCanvas.h"
#include "include/core/SkFont.h"
#include "include/core/SkColor.h"
#include "include/core/SkGraphics.h"
#include "include/core/SkSurface.h"
#include "include/effects/SkGradientShader.h"
#include "modules/skottie/include/Skottie.h"
#include "tools/Resources.h"

#include "SkottieViewerApp.h"

class MultiFrameResourceProvider final : public skresources::ResourceProvider {
public:
    sk_sp<skresources::ImageAsset> loadImageAsset(const char[], const char[],
                                                    const char[]) const override {
        return skresources::MultiFrameImageAsset::Make(
                    GetResourceAsData("images/flightAnim.gif"));
    }
};

SkottieViewerApp::SkottieViewerApp( ) 
    : fAnimation(nullptr) {

}

SkottieViewerApp::~SkottieViewerApp() {

}

void SkottieViewerApp::setup() {
    const char *skottie_filename = 
        //"skottie/skottie_sample_1.json";
        //"skottie/skottie_sample_2.json";
        //"skottie/skottie-glow-spread.json";
        "skottie/skottie-outerglow-style.json";
        //"skottie/skottie_sample_multiframe.json";

    if (auto stream = GetResourceAsStream(skottie_filename)) {
        fAnimation = skottie::Animation::Builder()
                        .make(stream.get());
        fAnimation->seek(0);
        printf( "Animation OK\n" );
    }
    fAnimTimer.run();
}

void SkottieViewerApp::draw( SkCanvas *canvas ) {
    canvas->clear(SK_ColorWHITE);
    if ( fAnimation == nullptr ) {
        return;
    }
    
    fAnimTimer.updateTime();
    double nanos = fAnimTimer.nanos();

    const auto duration = fAnimation->duration();
    fAnimation->seek(std::fmod(1e-9 * nanos, duration) / duration);  

    auto dest = SkRect::MakeWH(800, 800);
    fAnimation->render(canvas, &dest);  
}
