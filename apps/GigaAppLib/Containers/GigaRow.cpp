#include "GigaRow.h"
#include "../Widgets/GigaIcon.h"
#include "../Widgets/GigaText.h"

GigaRow::GigaRow() {
    _background = false;
    _gap = 1;
}

GigaRow::~GigaRow() {
}

void GigaRow::updateUI() {
    GigaWidget::updateUI();
    int hh = 0;
    for( int i=0; i<_children.size(); i++ ) {
        GigaWidget *w = _children[i];
        w->posn( 0, hh );
        hh += w->height() + _gap;
    }
}

GigaRow &Row() {
    GigaRow *w = new GigaRow();
    widgets_storage.push_back( w );
    return *w;      
}

int GigaRow::_contentWidth() {
    int n = 0;
    for( int i=0; i<_children.size(); i++ ) {
        GigaWidget *w = _children[i];
        if( w->width() > n ) {
            n = w->width();
        }
    }    
    return n;
}

int GigaRow::_contentHeight() {
    int hh = 0;
    for( int i=0; i<_children.size(); i++ ) {
        GigaWidget *w = _children[i];
        hh += w->height() + _gap;
    }
    return hh - _gap;
}