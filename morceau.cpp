#include "morceau.h"


morceau::morceau(): QGraphicsObject(){

}


void morceau::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawPixmap(this->m_pix.rect(),this->m_pix);
}

QRectF morceau::boundingRect() const{
    return this->m_pix.rect();
}


QPixmap morceau::getPix(){
    return this->m_pix;
}

void morceau::setPix(QPixmap pix){
    this->m_pix=pix;
}


QPointF morceau::getCentre(){
    return QPointF(this->x()+this->boundingRect().width()/2,this->y()+this->boundingRect().width()/2);

}

bool morceau::collisionWithArea(QPointF positionmorceau){
    if(positionmorceau.x()>=0 && positionmorceau.y()>=20 && positionmorceau.x()<=1700 && positionmorceau.y()<=1000)
        return true;
    return false;

}

void morceau::movemorceau(QPointF EndPos){
    if (this->collisionWithArea(EndPos)){
    this->setPos(EndPos);
}
}
qreal morceau::getSpeed(){
    return this->m_speed;
}

void morceau::setSpeed(qreal speed){
    this->m_speed=speed;
}
