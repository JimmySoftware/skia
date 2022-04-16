#ifndef __DEMO_APP_H__
#define __DEMO_APP_H__

#include "../../GigaAppLib/GigaApp.h"

class DemoApp : public GigaApp {
public:
    static DemoApp *createApp();
    virtual void setup() override {}
    virtual void draw( SkCanvas &canvas ) override {}    
    virtual void drawLayers( SkCanvas &canvas ) override { GigaApp::drawLayers( canvas ); }
    virtual void onResize( int width, int height, float scale ) override { GigaApp::onResize( width, height, scale ); }   
    virtual bool onKey(skui::Key k, skui::InputState state, skui::ModifierKey modifiers) override { 
        return GigaApp::onKey( k, state, modifiers ); 
    } 
    virtual bool onMouse(int x, int y, skui::InputState state, skui::ModifierKey modifiers ) override {
        return GigaApp::onMouse( x, y, state, modifiers );
    }
private:
    
};

#endif