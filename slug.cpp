#include "slug.h"
#include "player.h"

slug::slug()
{
    this->setPix(QPixmap(":/Other/slug_41.png"));
    this->setPos(890,550);
    this->setSpeed(5.0);
    this->setFlag(GraphicsItemFlag::ItemIsMovable);

}

int slug::getTaken(){
    return this->m_taken;
}

void slug::setTaken(int taken){
    this->m_taken=taken;
}

player *slug::getOwner(){
    return this->m_owner;
}

void slug::setOwner(player *owner){
    this->m_owner=owner;

}

//set a slug position front of player when collide

void slug::setPosslug(player *player){
    switch(player->getDirection()){
    case machinaK::Right :
        this->setPos(player->x()+20,player->y()+13);
        break;
    case machinaK::Left :
        this->setPos(player->x()+7,player->y()+13);
        break;
    case machinaK::Up :
        this->setPos(player->x()+15,player->y()+8);
        break;
    case  machinaK::Down :
        this->setPos(player->x()+15,player->y()+20);
        break;
    case machinaK::RightUp :
        this->setPos(player->x()+18,player->y()+13);
        break;
    case machinaK::LeftUp :
        this->setPos(player->x()+10,player->y()+10);
        break;
    case machinaK::LeftDown :
        this->setPos(player->x()+10,player->y()+15);
        break;
    case  machinaK::RightDown :
        this->setPos(player->x()+18,player->y()+15);
        break;

    }
}

//initialize the position of the slug when a goal is scored

void slug::initialise(){
    this->setPos(890,550);
}


//stock a direction of slug when we move it

void slug::setDirectioMove(int direction){
    this->m_direction=direction;
}

//retrieve a direction of slug when we move it

int slug::getDirectioMove(){
    return this->m_direction;
}


//---Method that reports a goal---
bool slug::but(){
    //---Goal in the right cage---
    if(this->x() > 1600)
    {
        if(this->y() < 600 && this->y() > 450)
        {
            return true;
        }
    }
    //---Goal in the left cage---

    if(this->x() < 60)
    {
        if(this->y() < 600 && this->y() > 450)
        {
            return true;
        }
    }
    return false;

}

bool slug:: sortieDeBut(){

    if(this->x() > 1600)
    {
        if(this->y() > 600 || this->y() < 450)
        {
            return true;
        }
    }
    if(this->x() < 60)
    {
        if(this->y() > 600 || this->y() < 450)
        {
            return true;
        }
    }
    return false;

}
