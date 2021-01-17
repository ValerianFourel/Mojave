#include "LegionScreen.h"

LegionScreen::LegionScreen()
{
    timer = new QTimer(this);
    duration = 300;
    QObject::connect(timer ,  SIGNAL(timeout ()),this,SLOT(setDuration()));
    this->setDigitCount(4);
    timer->start(1000);


}

void LegionScreen::setDuration()
{
    if(duration < 0)
    {
        timer->stop();
    }
    else
    {
        this->display(duration--);
    }

}
