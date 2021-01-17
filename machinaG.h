#ifndef machinaG_H
#define machinaG_H
#include <QGraphicsView>
#include "machina.h"
#include "kernel.h"
#include <QKeyEvent>

class Mojave;
class machinaG : public machina, public QGraphicsView
{
public:
    machinaG(kernel *kernel);
    kernel *getkernel();
    Mojave * getMojave();
    void setmachinaMojave(Mojave * Mojave);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
private:

        Mojave *m_Mojave;
     kernel * m_kernel;
};

#endif // machinaG_H
