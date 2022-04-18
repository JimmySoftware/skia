#include "GigaColumn.h"
#include "../Widgets/GigaIcon.h"
#include "../Widgets/GigaText.h"

GigaColumn::GigaColumn() {
    _background = false;
    _gap = 5;
}

GigaColumn::~GigaColumn() {
}

void GigaColumn::updateUI() {
    GigaWidget::updateUI();
    int ww = 0;
    for( int i=0; i<_children.size(); i++ ) {
        GigaWidget *w = _children[i];
        w->posn( ww, (_height - w->height())/2 );
        ww += w->width() + _gap;
    }
}

GigaWidget &GigaColumn::child( GigaWidget &c ) {
    return GigaWidget::child( c );
}

GigaColumn &Column() {
    GigaColumn *w = new GigaColumn();
    widgets_storage.push_back( w );
    return *w;      
}

int GigaColumn::_contentWidth() {
    int ww = 0;
    for( int i=0; i<_children.size(); i++ ) {
        GigaWidget *w = _children[i];
        ww += w->width() + _gap;
    }
    return ww - _gap;
}

int GigaColumn::_contentHeight() {
    int n = 0;
    for( int i=0; i<_children.size(); i++ ) {
        GigaWidget *w = _children[i];
        if( w->height() > n ) {
            n = w->height();
        }
    }    
    return n;
}