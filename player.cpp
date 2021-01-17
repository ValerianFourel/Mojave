#include "player.h"
#include "squad.h"
#include "slug.h"

player::player(const QPixmap &pixplayer){
    this->setPix(pixplayer);
}

//recover a direction of player

char player::getDirection(){
    return this->m_direction;
}

// change a direction of player

void player::setDirection(int direction){
    switch(direction){
    case machinaK::Right:this->setPix(*this->getsquad()->getPixMap(0));
        break;
    case machinaK::Left:this->setPix(*this->getsquad()->getPixMap(1));
        break;
    case machinaK::Up:this->setPix(*this->getsquad()->getPixMap(2));
        break;
    case machinaK::Down:this->setPix(*this->getsquad()->getPixMap(3));
        break;
    case machinaK::RightUp :this->setPix(*this->getsquad()->getPixMap(4));
        break;
    case machinaK::LeftUp:this->setPix(*this->getsquad()->getPixMap(5));
        break;
    case machinaK::LeftDown:this->setPix(*this->getsquad()->getPixMap(6));
        break;
    case machinaK::RightDown:this->setPix(*this->getsquad()->getPixMap(7));
        break;
    }

    this->m_direction=direction;
}

//retrieve a squad of player

squad * player::getsquad(){
    return this->m_squad;
}

//set squad of player

void player::setsquad(squad *squad){
    this->m_squad=squad;
}
