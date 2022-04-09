#ifndef __FPS_LAYER_H__
#define __FPS_LAYER_H__

#include <chrono>
#include "GigaAppLayer.h"
#include "include/core/SkColor.h"

class FPSLayer : public GigaAppLayer {
public:
    FPSLayer( SkColor c=SK_ColorGRAY, bool bVisible=false );
    virtual ~FPSLayer() override;

    void onResize( int w, int h, float scale ) override;
    void onUpdate() override;
    void onPaint( SkCanvas& canvas ) override;
    bool onChar(SkUnichar c, skui::ModifierKey) override;

    SkColor color;
    
private:
    long frames;
    float scale;

    std::chrono::high_resolution_clock::time_point beginTimeStamp;
    std::chrono::high_resolution_clock::time_point lastTimeStamp;    

    double frame_time;
    double elapse_time;
    double fps;    

    // https://stackoverflow.com/questions/8501706/how-to-get-the-cpu-usage-in-c
    clock_t beginCPUTime;
    clock_t lastCPUTime;

    clock_t elapsedCPUTime;

    double cpuUsage;
};

#endif //__FPS_LAYER_H__