#ifndef __GIGA_ROW_H__
#define __GIGA_ROW_H__

#include "../GigaWidget.h"
#include "../Widgets/GigaIcon.h"
#include "../Widgets/GigaText.h"

class GigaRow : public GigaWidget {
public:
    GigaRow();
    virtual ~GigaRow() override;

    virtual int _contentWidth() override;
    virtual int _contentHeight() override;  

    virtual void updateUI() override;

protected:
    int _gap;

    virtual void _draw_content(SkCanvas &canvas) override {}
};

GigaRow &Row();

#endif //__GIGA_ROW_H__