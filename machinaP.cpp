#include "machinaP.h"
#include "morceau.h"
#include "squad.h"
#include "math.h"
#include "player.h"
#include "slug.h"
#include "machinaG.h"
#include "machinaK.h"
#include <iostream>
#include <QTimeLine>
#include <QGraphicsItemAnimation>

#include <time.h>

machinaP::machinaP(Kernel * kernel){
    m_kernel=kernel;
}

//Compute a next position of morceau then move it at morceau class

void machinaP::computeNextPosition(morceau * morceau,int direction){
    switch( direction){
    case machinaK::Right:{
        morceau->movemorceau(QPointF(morceau->x() + morceau->getSpeed(),morceau->y()));
        break;
    }
    case machinaK::Left:{
        morceau->movemorceau(QPointF(morceau->x() - morceau->getSpeed(),morceau->y()));
        break;
    }
    case machinaK::Up:{
        morceau->movemorceau(QPointF(morceau->x(),morceau->y() - morceau->getSpeed()));

        break;
    }
    case machinaK::Down:{
        morceau->movemorceau(QPointF(morceau->x(),morceau->y() + morceau->getSpeed()));

        break;
    }
    case machinaK::LeftUp:{
        morceau->movemorceau(QPointF(morceau->x() - morceau->getSpeed(),morceau->y() - morceau->getSpeed()));


        break;
    }
    case machinaK::RightUp:{
        morceau->movemorceau(QPointF(morceau->x() + morceau->getSpeed(),morceau->y() - morceau->getSpeed()));
        break;
    }
    case machinaK::LeftDown:{
        morceau->movemorceau(QPointF(morceau->x() - morceau->getSpeed(),morceau->y() + morceau->getSpeed()));

        break;
    }
    case machinaK::RightDown:{
        morceau->movemorceau(QPointF(morceau->x() + morceau->getSpeed(),morceau->y() + morceau->getSpeed()));

        break;
    }

    default:
        break;
    }

}


//Check colision beetween two graphics morceau

bool machinaP::checkCollide(morceau *morceau1,morceau *morceau2)
{
    if((morceau2->x() >= morceau1->x() + morceau1->getPix().rect().width())
            || (morceau2->x() + morceau2->getPix().rect().width() <= morceau1->x())
            || (morceau2->y() >= morceau1->y() + morceau1->getPix().rect().height())
            || (morceau2->y() + morceau2->getPix().rect().height() <= morceau1->y()))
        return false;
    else
        return true;
}


qreal machinaP::computeTimeOfMove(morceau *morceau, const QPointF &end){
    return (this->getDistance(morceau->pos(),end)/(qreal)morceau->getSpeed())*10;

}

//distance entre deux point
qreal machinaP::getDistance(QPointF const& x1,QPointF const& x2){
    return sqrt(pow((x1.x()-x2.x()),2)+ pow( x1.y()-x2.y(),2));
}

//Animate a translation of morceau

void machinaP::animTranslation(morceau *morceau, QPointF const& end, qreal const& time, bool scaled){
    QPropertyAnimation *anim=new QPropertyAnimation(morceau,"pos");
    anim->setDuration(time);
    if(scaled)
        this->scale(morceau,time);
    anim->setStartValue(morceau->pos());
    morceau->movemorceau(end);
    anim->setEndValue(end);
    anim->setEasingCurve(QEasingCurve::OutQuad);
    anim->start(QPropertyAnimation::DeleteWhenStopped);

}


void machinaP::scale(morceau *morceau, const qreal &time){
    QPropertyAnimation *anim=new QPropertyAnimation(morceau,"scale");
    anim->setDuration(time);
    anim->setStartValue(1);
    anim->setKeyValueAt(0.001,2);
    anim->setEndValue(1);
    anim->setEasingCurve(QEasingCurve::InCubic);
    anim->start();
}


QPointF machinaP::randomPoint(qreal x1, qreal x2, qreal y1, qreal y2 ){
    srand (time(NULL));
    return QPointF( (rand() % (int)(x2-x1) + (int)x2 ),(rand() % (int) (y2-y1) + (int)y2));
}
