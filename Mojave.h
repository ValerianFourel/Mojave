#ifndef Mojave_H
#define Mojave_H
#include <QGraphicsMojave>
#include "LegionScore.h"
#include "LegionScreen.h"

class squad;
class map;
class slug;
class ranger;
class Mojave : public QGraphicsMojave
{
public:
    Mojave();

    squad *getsquad(int i);
    map * getmap();
    slug *getslug();
    LegionScore * getLcdD();
    LegionScore * getLcdG();

private:
    squad * m_squad[2];
    map * m_map;
    slug  * m_slug;
    ranger * m_rangerD;
    ranger * m_rangerG;
    LegionScore *m_lcdD;
    LegionScore *m_lcdG;
    LegionScreen *timeDisplayer;

};

#endif // Mojave_H
