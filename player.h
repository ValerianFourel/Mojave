#ifndef player_H
#define player_H
#include "morceau.h"

class squad;
class player: public morceau
{
public:

    player(QPixmap const&  pixplayer);
    //void sPass();
    void sShoot();
    void sSpeed();
    squad *getsquad();
    void setsquad(squad *squad);
    void setDirection(int direction);
    char getDirection();


private:
    squad * m_squad;
    int m_direction;
};

#endif // player_H
