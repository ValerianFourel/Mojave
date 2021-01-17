#ifndef map_H
#define map_H
#include "morceau.h"

class map : public morceau
{
public:
    map();

    QPixmap getPixMap();

private:
    int m_height;
    int m_width;
    QPixmap pixmap;
};

#endif // map_H
