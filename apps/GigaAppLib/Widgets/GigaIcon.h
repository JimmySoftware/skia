#ifndef __GIGA_ICON_H__
#define __GIGA_ICON_H__

#include "GigaText.h"

class GigaIcon : public GigaText {
public:
    GigaIcon( const uint16_t code );
    virtual ~GigaIcon() override;
};

GigaIcon &Icon( const uint16_t code );

#endif //__GIGA_ICON_H__
