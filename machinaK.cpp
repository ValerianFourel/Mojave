#include "machinaK.h"
#include "machinaG.h"
#include "kernel.h"
#include "squad.h"
#include "player.h"
#include "slug.h"
#include "ranger.h"
#include "machinaP.h"
#include <iostream>

#include <time.h>


machinaK::machinaK(kernel *kernel){
    this->m_kernel=kernel;
}

void machinaK::TimeEvent(QTimerEvent *){
    if (m_Player[0].Left && m_Player[0].Up){
        this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::LeftUp);
        this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(LeftUp);
    }

    else
        if (m_Player[0].Right && m_Player[0].Up){
            this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::RightUp);
            this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(RightUp);
        }
        else

            if (m_Player[0].Down && m_Player[0].Left) {
                this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::LeftDown);
                this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(LeftDown);
            }
            else

                if (m_Player[0].Down && m_Player[0].Right) {
                    this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::RightDown);
                    this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(RightDown);}
                else
                    if (m_Player[0].Right){
                        this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::Right);
                        this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(Right);
                    }
                    else
                        if (m_Player[0].Left){
                            this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::Left);
                            this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(Left);
                        }
                        else
                            if (m_Player[0].Down){
                                this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::Down);
                                this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(Down);
                            }
                            else
                                if (m_Player[0].Up) {
                                    this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::Up);
                                    this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(Up);
                                }
                                else
                                    if(m_Player[0].Space){
                                        m_Player[0].Space=false;
                                        if (this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer()!=this->m_kernel->getmachinaG()->getMojave()->getslug()->getOwner())
                                            this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->changeFocusedplayer(this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer());
                                    }
                                    else
                                        if(m_Player[0].longPass){
                                            m_Player[0].longPass=false;
                                            this->slugPassManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),false);
                                        }
                                        else
                                            if(m_Player[0].shoot){
                                                m_Player[0].shoot=false;
                                                this->slugShootManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug());
                                            }
                                            else
                                                if(m_Player[0].pass){
                                                    m_Player[0].pass=false;
                                                    this->slugPassManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),true);
                                                }


    if (m_Player[1].Left && m_Player[1].Up){
        this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::LeftUp);
        this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(LeftUp);

    }

    else
        if (m_Player[1].Right && m_Player[1].Up){
            this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::RightUp);
            this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(RightUp);
        }
        else

            if (m_Player[1].Down && m_Player[1].Left) {

                this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::LeftDown);
                this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(LeftDown);
            }
            else

                if (m_Player[1].Down && m_Player[1].Right) {
                    this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::RightDown);
                    this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(RightDown);
                }
                else
                    if (m_Player[1].Right){
                        this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::Right);
                        this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(Right);
                    }
                    else
                        if (m_Player[1].Left){
                            this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::Left);
                            this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(Left);
                        }
                        else
                            if (m_Player[1].Down){
                                this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::Down);
                                this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(Down);
                            }
                            else
                                if (m_Player[1].Up) {
                                    this->directionManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),machinaK::Up);
                                    this->m_kernel->getmachinaG()->getMojave()->getslug()->setDirectioMove(Up);
                                }
                                else
                                    if(m_Player[1].Space){
                                        m_Player[1].Space=false;
                                        if (this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer()!=this->m_kernel->getmachinaG()->getMojave()->getslug()->getOwner())
                                            this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->changeFocusedplayer(this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer());
                                    }
                                    else
                                        if(m_Player[1].longPass){
                                            m_Player[1].longPass=false;
                                            this->slugPassManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),false);
                                        }
                                        else
                                            if(m_Player[1].shoot){
                                                m_Player[1].shoot=false;
                                                this->slugShootManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug());
                                            }
                                            else
                                                if(m_Player[1].pass){
                                                    m_Player[1].pass=false;
                                                    this->slugPassManager(this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getFocusedplayer(),this->m_kernel->getmachinaG()->getMojave()->getslug(),true);
                                                }
}



void machinaK::pressEvent(QKeyEvent *event) {
    switch(event->key()) {
    case (Qt::Key_Left):
        m_Player[0].Left = true;
        break;
    case (Qt::Key_Right):
        m_Player[0].Right = true;
        break;
    case (Qt::Key_Up):
        m_Player[0].Up = true;
        break;
    case (Qt::Key_Down):
        m_Player[0].Down = true;
        break;
    case (Qt::Key_2):
        m_Player[0].pass=true;
        break;
    case (Qt::Key_3):
        m_Player[0].shoot=true;
        break;
    case (Qt::Key_1):
        m_Player[0].longPass=true;
        break;
    case (Qt::Key_0):
        m_Player[0].Space=true;
        break;
    case (Qt::Key_J):
        m_Player[1].pass=true;
        break;
    case (Qt::Key_K):
        m_Player[1].shoot=true;
        break;
    case (Qt::Key_H):
        m_Player[1].longPass=true;
        break;
    case (Qt::Key_Q):
        m_Player[1].Left = true;
        break;
    case (Qt::Key_D):
        m_Player[1].Right = true;
        break;
    case (Qt::Key_Z):
        m_Player[1].Up = true;
        break;
    case (Qt::Key_S):
        m_Player[1].Down = true;
        break;
    case (Qt::Key_Space):
        m_Player[1].Space=true;
        break;
    }
    this->m_kernel->getmachinaG()->update();
}


void machinaK::releaseEvent(QKeyEvent *event) {
    switch(event->key()) {

    case Qt::Key_Left :
        m_Player[0].Left = false;
        break;
    case  Qt::Key_Right :
        m_Player[0].Right = false;
        break;
    case Qt::Key_Up :
        m_Player[0].Up = false;
        break;
    case Qt::Key_Down :
        m_Player[0].Down = false;
        break;
    case Qt::Key_Q :
        m_Player[1].Left = false;
        break;
    case  Qt::Key_D :
        m_Player[1].Right = false;
        break;
    case Qt::Key_Z :
        m_Player[1].Up = false;
        break;
    case Qt::Key_S :
        m_Player[1].Down = false;
        break;

    default:
        break;
    }

}




void machinaK::directionManager(player *player,slug *slug,int direction){
    player->setDirection(direction);
    this->m_kernel->getmachinaP()->computeNextPosition(player,direction);
    if(this->m_kernel->getmachinaP()->checkCollide(player,slug)){
        slug->setOwner(player);
        slug->setTaken(1);
        slug->setSpeed(player->getSpeed());
        slug->setPosslug(player);
        this->m_kernel->getmachinaP()->computeNextPosition(slug,direction);

    }

    if(slug->but()){
        this->GoalManager(slug->getDirectioMove());
    }
    else if(slug->sortieDeBut()){//---Goal kick---
        //---Throw in the corresponding side---
        if(slug->getDirectioMove() == Right){
            this->m_kernel->getmachinaG()->getMojave()->getslug()->setPos(1540,515);
        }
        else if(slug->getDirectioMove() == Left){
            this->m_kernel->getmachinaG()->getMojave()->getslug()->setPos(130,515);

        }

    }
}






void machinaK::slugPassManager(player *player,slug *slug,bool scaled){
    if(slug->getTaken()){
        slug->setTaken(0);
        QPointF destinationslug=player->getsquad()->getReceiverOfslug()->pos();
        qreal time=this->m_kernel->getmachinaP()->computeTimeOfMove(player,destinationslug);
        this->m_kernel->getmachinaP()->animTranslation(slug,destinationslug,time,scaled);
        slug->setOwner(NULL);
        player->getsquad()->changeFocusedplayer(player->getsquad()->getFocusedplayer());
    }
}

void machinaK::slugShootManager(player *player,slug *slug){

    qreal time;
    if (slug->getTaken()){
        if(player->getsquad()->getName()=='1'){
            if (slug->getDirectioMove()==Right || slug->getDirectioMove()==Left){
                if(slug->pos().x()<=1300){
                    time=this->m_kernel->getmachinaP()->computeTimeOfMove(player,QPointF(slug->pos().x()+400,slug->pos().y()));
                    this->m_kernel->getmachinaP()->animTranslation(slug,QPointF(slug->pos().x()+400,slug->pos().y()),time,true);
                    slug->setTaken(0);
                }else {
                    QPointF randPos=this->m_kernel->getmachinaP()->randomPoint(1585,1620,500,550);
                    time=this->m_kernel->getmachinaP()->computeTimeOfMove(player,randPos);
                    this->m_kernel->getmachinaP()->animTranslation(slug,randPos,time,true);
                    slug->setTaken(0);

                }
            } else
                if (slug->getDirectioMove()==RightUp || slug->getDirectioMove()==LeftUp || slug->getDirectioMove()==RightDown || slug->getDirectioMove()==LeftDown){
                    if(slug->pos().x()<=1300){
                        time=this->m_kernel->getmachinaP()->computeTimeOfMove(player,QPointF(slug->pos().x()+400,slug->pos().y()+400));
                        this->m_kernel->getmachinaP()->animTranslation(slug,QPointF(slug->pos().x()+400,slug->pos().y()),time,true);
                        slug->setTaken(0);
                    }else {
                        QPointF randPos=this->m_kernel->getmachinaP()->randomPoint(1585,1620,500,550);
                        time=this->m_kernel->getmachinaP()->computeTimeOfMove(player,randPos);
                        this->m_kernel->getmachinaP()->animTranslation(slug,randPos,time,true);
                        slug->setTaken(0);

                    }
                }
        }else
            if(player->getsquad()->getName()=='2'){
                if (slug->getDirectioMove()==Right || slug->getDirectioMove()==Left){
                    if(slug->pos().x()>=300){
                        time=this->m_kernel->getmachinaP()->computeTimeOfMove(player,QPointF(slug->pos().x()-400,slug->pos().y()));
                        this->m_kernel->getmachinaP()->animTranslation(slug,QPointF(slug->pos().x()-400,slug->pos().y()),time,true);
                        slug->setTaken(0);
                    }else {
                        QPointF randPos=this->m_kernel->getmachinaP()->randomPoint(20,40,500,550);
                        time=this->m_kernel->getmachinaP()->computeTimeOfMove(player,randPos);
                        this->m_kernel->getmachinaP()->animTranslation(slug,randPos,time,true);
                        slug->setTaken(0);

                    }
                } else
                    if (slug->getDirectioMove()==RightUp || slug->getDirectioMove()==LeftUp ){
                        if(slug->pos().x()>=300){
                            time=this->m_kernel->getmachinaP()->computeTimeOfMove(player,QPointF(slug->pos().x()-400,slug->pos().y()-400));
                            this->m_kernel->getmachinaP()->animTranslation(slug,QPointF(slug->pos().x()-400,slug->pos().y()-400),time,true);
                            slug->setTaken(0);
                        }else {
                            QPointF randPos=this->m_kernel->getmachinaP()->randomPoint(20,40,500,550);
                            time=this->m_kernel->getmachinaP()->computeTimeOfMove(player,randPos);
                            this->m_kernel->getmachinaP()->animTranslation(slug,randPos,time,true);
                            slug->setTaken(0);

                        }
                    }
                    else if(slug->getDirectioMove()==RightDown || slug->getDirectioMove()==LeftDown){
                        if(slug->pos().x()>=300){
                            time=this->m_kernel->getmachinaP()->computeTimeOfMove(player,QPointF(slug->pos().x()-400,slug->pos().y()+400));
                            this->m_kernel->getmachinaP()->animTranslation(slug,QPointF(slug->pos().x()-400,slug->pos().y()+400),time,true);
                            slug->setTaken(0);
                        }else {
                            QPointF randPos=this->m_kernel->getmachinaP()->randomPoint(20,40,500,550);
                            time=this->m_kernel->getmachinaP()->computeTimeOfMove(player,randPos);
                            this->m_kernel->getmachinaP()->animTranslation(slug,randPos,time,true);
                            slug->setTaken(0);

                        }

                    }
            }
    }


    slug->setOwner(NULL);
    slug->setDirectioMove(slug->getDirectioMove());

    if(slug->but())
    {
        this->GoalManager(slug->getDirectioMove());
    }
    else if(slug->sortieDeBut()){//---Goal kick---
        //---Throw in the corresponding side---
        if(slug->getDirectioMove() == Right){
            this->m_kernel->getmachinaG()->getMojave()->getslug()->setPos(1540,515);
        }else if(slug->getDirectioMove() == Left){
            this->m_kernel->getmachinaG()->getMojave()->getslug()->setPos(130,515);
        }
    }


}

void machinaK::GoalManager(int direction){
    //-----------------------------CODE TEST POUR LA GESTION DU BUT---------------------------------------//

    if(direction == Right || direction== RightUp || direction==RightDown)
    {
        //---Changing the score in a goal from the right ranger---
        this->m_kernel->getmachinaG()->getMojave()->getLcdG()->display(this->m_kernel->getmachinaG()->getMojave()->getLcdG()->setButsquad1());
        //---Repositionning of the players in the center to give the kick-off---
        this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getStriker()->setPos(830,480);
        this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getStriker()->setDirection(machinaK::Down);

        this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getDefender()->setPos(830,530);
        this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getDefender()->setDirection(machinaK::Up);
        //---Repositionning players in their camps---
        this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getStriker()->setPos(600,507);
        this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getStriker()->setDirection(machinaK::Right);
        this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getDefender()->setPos(500,507);
        this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getDefender()->setDirection(machinaK::Right);

    }else if (direction == Left){

        //---Changing the score in a goal from the left ranger---
        this->m_kernel->getmachinaG()->getMojave()->getLcdD()->display(this->m_kernel->getmachinaG()->getMojave()->getLcdD()->setButsquad2());
        //---Repositionning of the players in the center to give the kick-off---
        this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getStriker()->setPos(825,480);
        this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getStriker()->setDirection(machinaK::Down);

        this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getDefender()->setPos(825,530);
        this->m_kernel->getmachinaG()->getMojave()->getsquad(1)->getDefender()->setDirection(machinaK::Up);

        //---Repositionning players in their camps---
        this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getStriker()->setPos(900,507);
        this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getStriker()->setDirection(machinaK::Left);

        this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getDefender()->setPos(1200,507);
        this->m_kernel->getmachinaG()->getMojave()->getsquad(2)->getDefender()->setDirection(machinaK::Left);

    }
    //---Repositionning the slug in the centre--
    this->m_kernel->getmachinaG()->getMojave()->getslug()->setPos(834,520);

    this->m_kernel->getmachinaG()->repaint();
}
