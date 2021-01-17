#include "Mojave.h"
#include "map.h"
#include "squad.h"
#include "player.h"
#include "slug.h"
#include "ranger.h"

Mojave::Mojave()
{
    //---map creation
    this->m_map = new map();
    this->setMojaveRect(this->m_map->getPix().rect());
    this->setBackgroundBrush(this->m_map->getPix());

    //--- ranger creation---
    this->m_rangerD = new ranger();
    QPixmap rangerD = QPixmap(":/ranger/Rightranger.png");
    this->m_rangerD->setPix(rangerD);
    this->m_rangerD->setPos(1585, 455);
    this->addItem(this->m_rangerD);

    this->m_rangerG = new ranger();
    QPixmap rangerG = QPixmap(":/ranger/Leftranger.png");
    this->m_rangerG->setPix(rangerG);
    this->m_rangerG->setPos(60, 455);
    this->addItem(this->m_rangerG);

    //--slug creation
    this->m_slug=new slug();
    this->addItem(this->m_slug);

    //--First squad creation
    this->m_squad[1] = new squad(1);
    this->addItem(this->m_squad[1]->getDefender());
    this->addItem(this->m_squad[1]->getGoalKeeper());
    this->addItem(this->m_squad[1]->getStriker());

    //--Seconde squad creation
    this->m_squad[2] = new squad(2);
    this->addItem(this->m_squad[2]->getDefender());
    this->addItem(this->m_squad[2]->getGoalKeeper());
    this->addItem(this->m_squad[2]->getStriker());

    // panneanux d'affichage des scores
    this->m_lcdD = new LCDScore();
    this->m_lcdG = new LCDScore();
    this->m_lcdG->setGeometry(700,0,70,50);
    this->m_lcdD->setGeometry(900,0,70,50);
    this->m_lcdD->setSegmentStyle(QLCDNumber::Flat);
    this->m_lcdG->setSegmentStyle(QLCDNumber::Flat);
    this->addWidget(this->m_lcdD);
    this->addWidget(this->m_lcdG);

    //panneau d'affichage du temps
    timeDisplayer = new LCDScreen();
    timeDisplayer->setSegmentStyle(QLCDNumber::Flat);
    timeDisplayer->setGeometry(800,0,70,50);
    this->addWidget(timeDisplayer);


}


squad * Mojave::getsquad(int i){
    return this->m_squad[i];
}

map * Mojave::getmap(){
    return this->m_map;
}

slug * Mojave::getslug(){
    return this->m_slug;
}

LCDScore * Mojave::getLcdD()
{
    return this->m_lcdD;
}

LCDScore * Mojave::getLcdG()
{
    return this->m_lcdG;
}
