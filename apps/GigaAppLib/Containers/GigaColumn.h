#ifndef __GIGA_COLUMN_H__
#define __GIGA_COLUMN_H__

#include "../GigaWidget.h"
#include "../Widgets/GigaIcon.h"
#include "../Widgets/GigaText.h"

class GigaColumn : public GigaWidget {
public:
    GigaColumn();
    virtual ~GigaColumn() override;

    virtual int _contentWidth() override;
    virtual int _contentHeight() override;  

    virtual void updateUI() override;

    virtual GigaWidget &child( GigaWidget &c ) override;

protected:
    int _gap;

    virtual void _draw_content(SkCanvas &canvas) override {}
};

GigaColumn &Column();

#endif //__GIGA_COLUMN_H__