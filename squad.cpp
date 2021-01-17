#include "squad.h"
#include "player.h"
#include "machinaK.h"
#include "ranger.h"

squad::squad(int i)
{

    if (i==1){
        this->m_squad[i]=":/squad1pix";
        m_name='1';

        // player image right
        this->m_tabPixplayer[0] = new QPixmap(this->m_squad[i]+"/kit 90.png");
        // player image left
        this->m_tabPixplayer[1] = new QPixmap(this->m_squad[i]+"/kit 270.png");
        // player image up
        this->m_tabPixplayer[2] = new QPixmap(this->m_squad[i]+"/kit 0.png");
        // player image down
        this->m_tabPixplayer[3] = new QPixmap(this->m_squad[i]+"/kit 180.png");
        //Diagonal Right Up
        this->m_tabPixplayer[4] = new QPixmap(this->m_squad[i]+"/kit 60.png");
        // Diagonal Left Up
        this->m_tabPixplayer[5] = new QPixmap(this->m_squad[i]+"/kit 300.png");
        // Diagonal Left Down
        this->m_tabPixplayer[6] = new QPixmap(this->m_squad[i]+"/kit 240.png");
        // Diagonal Right down
        this->m_tabPixplayer[7] = new QPixmap(this->m_squad[i]+"/kit 120.png");

        this->m_goalKeeper = new player(*this->m_tabPixplayer[0]);
        this->m_goalKeeper->setsquad(this);
        this->m_goalKeeper->setPos(90,507);
        this->m_goalKeeper->setSpeed(5.0);
        this->m_goalKeeper->setDirection(machinaK::Right);


        this->m_defender = new player(*this->m_tabPixplayer[0]);
        this->m_defender->setsquad(this);
        this->m_defender->setPos(510,520);
        this->m_defender->setSpeed(6);
        this->m_defender->setDirection(machinaK::Right);



        this->m_striker = new player(*this->m_tabPixplayer[0]);
        this->m_striker->setsquad(this);
        this->m_striker->setPos(900,600);
        this->m_striker->setDirection(machinaK::Right);
        this->m_focusedplayer=this->m_striker;
        this->m_striker->setSpeed(6);
    }
    else{
        this->m_squad[i]=":/squad2pix";
        m_name='2';

        // player image right
        this->m_tabPixplayer[0] = new QPixmap(this->m_squad[i]+"/kit 90.png");
        // player image left
        this->m_tabPixplayer[1] = new QPixmap(this->m_squad[i]+"/kit 270.png");
        // player image up
        this->m_tabPixplayer[2] = new QPixmap(this->m_squad[i]+"/kit 0.png");
        // player image down
        this->m_tabPixplayer[3] = new QPixmap(this->m_squad[i]+"/kit 180.png");
        //Diagonal Right Up
        this->m_tabPixplayer[4] = new QPixmap(this->m_squad[i]+"/kit 60.png");
        // Diagonal Left Up
        this->m_tabPixplayer[5] = new QPixmap(this->m_squad[i]+"/kit 300.png");
        // Diagonal Left Down
        this->m_tabPixplayer[6] = new QPixmap(this->m_squad[i]+"/kit 240.png");
        // Diagonal Right down
        this->m_tabPixplayer[7] = new QPixmap(this->m_squad[i]+"/kit 120.png");

        this->m_goalKeeper = new player(*this->m_tabPixplayer[1]);
        this->m_goalKeeper->setsquad(this);
        this->m_goalKeeper->setPos(1550,507);
        this->m_goalKeeper->setSpeed(5);
        this->m_goalKeeper->setDirection(machinaK::Left);


        this->m_defender = new player(*this->m_tabPixplayer[1]);
        this->m_defender->setsquad(this);
        this->m_defender->setPos(1200,507);
        this->m_defender->setSpeed(6);
        this->m_defender->setDirection(machinaK::Left);

        this->m_striker = new player(*this->m_tabPixplayer[1]);
        this->m_striker->setsquad(this);
        this->m_striker->setPos(1000,507);
        this->m_striker->setSpeed(6);

        this->m_focusedplayer=this->m_striker;
        this->m_striker->setDirection(machinaK::Left);
    }
this->m_nbGoal=0;

}


QPixmap *squad::getPixMap(int i)
{
    return this->m_tabPixplayer[i];
}

player * squad::getDefender(){
    return this->m_defender;
}

player *squad::getStriker(){
    return this->m_striker;
}

player *squad::getGoalKeeper(){
    return this->m_goalKeeper;
}

player *squad::getFocusedplayer(){
    return this->m_focusedplayer;
}

void squad::setFocusedplayer(player *player)
{
    this->m_focusedplayer = player;

}

void squad::changeFocusedplayer(player * focusedplayer){
    if(focusedplayer==this->m_defender){
        this->m_focusedplayer=this->m_striker;
    }
    else
        this->m_focusedplayer=this->m_defender;
}

int squad::getNbGoal(){
return this->m_nbGoal;
}

void squad::setNbGoal(int nbGoal){
this->m_nbGoal=nbGoal;
}

player* squad::getReceiverOfslug(){
if(this->getFocusedplayer()==this->m_defender){
    return this->m_striker;
}
else
    return this->m_defender;
}

char squad::getName(){
    return m_name;
}

void squad::setName(char name){
    this->m_name=name;
}
