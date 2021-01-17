
#ifndef machinaP_H
#define machinaP_H
#include "machina.h"
#include "kernel.h"
#include <QPropertyAnimation>
class slug;
class player;
class morceau;
class machinaP : public machina
{
public:
    kernel * m_kernel;
    machinaP(kernel *kernel);

    void computeNextPosition(morceau * morceau,int direction);
    void moveslug(slug * slug, float xMovement, float yMovement);
    bool checkCollide(morceau *morceau1,morceau *morceau2);
    qreal getDistance(QPointF const& x1,QPointF const& x2);
    qreal computeTimeOfMove(morceau *morceau, QPointF const& end);
    void animTranslation(morceau *morceau, const QPointF &end, const qreal &time, bool scaled);
    void scale(morceau *morceau,qreal const& time);
    QPointF randomPoint(qreal x1, qreal x2, qreal y1, qreal y2 );
    enum Direction {Right,Left,Up,Down,RightUp,LeftUp,LeftDown,RightDown};
};

#endif // machinaP_H
