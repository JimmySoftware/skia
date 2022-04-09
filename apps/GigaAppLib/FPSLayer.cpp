#include "FPSLayer.h"
#include <unistd.h>
#include "include/core/SkFont.h"
#if defined(SK_BUILD_FOR_WIN)
//#include <sysinfoapi.h>
#endif

static const int fontSize = 18;

FPSLayer::FPSLayer(SkColor c, bool bVisible ) 
    : frames(0) { 
        fVisible = bVisible; 
        color = c; 

        scale = 1.0;
}

FPSLayer::~FPSLayer() {}

void FPSLayer::onResize(int w, int h, float s) { scale = s; }

void FPSLayer::onUpdate() {
    if (frames == 0) {
        beginTimeStamp = std::chrono::high_resolution_clock::now();
        lastTimeStamp = beginTimeStamp;
        frame_time = 0;
        elapse_time = 0;

#if defined(SK_BUILD_FOR_WIN)
#else
        beginCPUTime = clock();
        lastCPUTime = beginCPUTime;
        elapsedCPUTime = 0;
#endif
    } else {
        auto endTimeStamp = std::chrono::high_resolution_clock::now();
        auto elapsed =
                std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeStamp - beginTimeStamp);
        elapse_time = elapsed.count() * 1e-9;

        auto frameElapsed =
                std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeStamp - lastTimeStamp);
        frame_time = frameElapsed.count() * 1e-9;

        lastTimeStamp = endTimeStamp;
        fps = (double)frames / elapse_time;



#if defined(SK_BUILD_FOR_WIN)
        //SYSTEM_INFO sys_info;
        //GetSystemInfo( &sys_info );
        //int core = sys_info.dwNumberOfProcessors;
#else
#ifndef __EMSCRIPTEN__
        clock_t endCPUTime = clock();
        elapsedCPUTime = endCPUTime-beginCPUTime;
        lastCPUTime = endCPUTime;

        int core = sysconf(_SC_NPROCESSORS_ONLN);
        cpuUsage = (double)elapsedCPUTime / CLOCKS_PER_SEC / core / (double)elapse_time * 100.0;
#endif
#endif

    }
    frames++;
}

void FPSLayer::onPaint(SkCanvas& canvas) {
    if (!fVisible) {
        return;
    }

    SkPaint paint;
    paint.setColor(color);
    SkFont font;
    font.setSize(SkIntToScalar(fontSize * scale));

    char message[128] = "";
    sprintf(message, "Frame rate: %.3f fps.", (float)fps);
    canvas.drawSimpleText(
            message, strlen(message), SkTextEncoding::kUTF8, 2, 2 + fontSize * scale, font, paint);
    //SkDebugf( "%s\n", message );

#if defined(SK_BUILD_FOR_WIN)
#else
    sprintf(message, "CPU Usage: %.3f%%", (float)cpuUsage);
    canvas.drawSimpleText(
            message, strlen(message), SkTextEncoding::kUTF8, 2, 2 + 2 * fontSize * scale, font, paint);
#endif            
}

bool FPSLayer::onChar(SkUnichar c, skui::ModifierKey) {
    //SkDebugf("On char %c\n", c);
    if ('\\' == c) {
        this->fVisible = !this->fVisible;
        return true;
    }
    return false;
}
