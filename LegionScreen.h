
#ifndef LegionScreen_H
#define LegionScreen_H

#include <QLCDNumber>
#include <QTimer>
#include <QTime>
class LegionScreen: public QLCDNumber
{
    Q_OBJECT

public:
    LegionScreen();


public slots:
    void setDuration();
private:
    QTimer *timer;
    int duration;
};
#endif // LegionScreen_H
