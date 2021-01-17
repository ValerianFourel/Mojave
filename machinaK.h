#ifndef machinaK_H
#define machinaK_H
#include <QKeyEvent>


class player;
class slug;
typedef struct  playerKeyPress playerKeyPress;
struct playerKeyPress{
    bool Left;
    bool Right;
    bool Up;
    bool Down;
    bool Space;
    bool pass;
    bool longPass;
    bool shoot;
    playerKeyPress(){
        Left=false;
        Right=false;
        Up=false;
        Down=false;
        Space=false;
        pass=false;
        longPass=false;
        shoot=false;
    }
};



class kernel;
class machinaG;
class squad;
class machinaK
{
private:
    playerKeyPress m_Player[2];

    kernel * m_kernel;
public:
    enum Direction {Right,Left,Up,Down,RightUp,LeftUp,LeftDown,RightDown};
    machinaK(kernel *kernel);
    void TimeEvent(QTimerEvent *);
    void pressEvent(QKeyEvent *event);
    void releaseEvent(QKeyEvent *event);
    void keyEventManager();
    void directionManager(player *player, slug *slug, int direction);
    void slugPassManager(player *player,slug *slug,bool scaled);
    void slugShootManager(player *player, slug *slug);
    void GoalManager(int direction);
};

#endif // machinaK_H
