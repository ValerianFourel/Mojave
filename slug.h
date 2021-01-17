#ifndef slug_H
#define slug_H
#include "morceau.h"
#include <QPixmap>

class player;
class slug : public morceau
{
public:
    slug();

    int getTaken();
    void setTaken(int taken);

    player *getOwner();
    void setOwner(player *owner);

    QPixmap getPixMap();
    void setPixMap(QPixmap pixslug);
    void setPosslug(player * player);
    void initialise();
    void setDirectioMove(int direction);
    int getDirectioMove();
    bool but();
    bool sortieDeBut();

private:
    int m_taken;
    int m_direction;
    player * m_owner;
    QPixmap m_pixslug;
};

#endif // slug_H
