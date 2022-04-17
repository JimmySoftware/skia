#include "GigaUtils.h"


#ifdef __EMSCRIPTEN__
void emscriptenDownloadAsset( GigaWidget *widget, 
    std::string url, 
    void (*onsuccess)(struct emscripten_fetch_t *fetch),
    void (*onerror)(struct emscripten_fetch_t *fetch) ) {
    emscripten_fetch_attr_t attr;
    emscripten_fetch_attr_init(&attr);

    strcpy(attr.requestMethod, "GET");

    std::string full_url = std::string( "/resources/") + url;
    
    attr.attributes = EMSCRIPTEN_FETCH_LOAD_TO_MEMORY;
    attr.userData = (void *)widget;
    attr.onsuccess = onsuccess;
    attr.onerror = onerror;
    emscripten_fetch(&attr, full_url.c_str());
}
#endif