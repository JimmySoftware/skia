#ifndef __GIGA_UTILS_H__
#define __GIGA_UTILS_H__

#include <string>
#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#include "emscripten/fetch.h"
#endif

#include "GigaWidget.h"

#ifdef __EMSCRIPTEN__
void emscriptenDownloadAsset( GigaWidget *widget, 
    std::string url, 
    void (*onsuccess)(struct emscripten_fetch_t *fetch),
    void (*onerror)(struct emscripten_fetch_t *fetch) );
#endif  

#endif //__GIGA_UTILS_H__