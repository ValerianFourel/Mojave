#ifndef morceau_H
#define morceau_H
#include <QGraphicsItem>
#include <QPainter>
#include "machinaK.h"

class morceau : public QGraphicsObject{
public:
    morceau();
    QPixmap getPix();
    void setPix(QPixmap pix);
    QPainter getPainter();
    QPointF getCentre();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    bool collisionWithArea(QPointF positionmorceau);
    void movemorceau(QPointF EndPos);
    qreal getSpeed();
    void setSpeed(qreal speed);

private:
    qreal m_speed;
    QPixmap m_pix;
};

#endif // morceau_H
