#ifndef squad_H
#define squad_H
#include "morceau.h"
#include <QPixmap>

class player;
class ranger;
class squad
{
public:
    squad(int i);
    QPixmap *getPixMap(int i);
    player *getDefender();
    player *getStriker();
    player *getGoalKeeper();
    player *getFocusedplayer();
    void setFocusedplayer(player *player);
    void changeFocusedplayer(player * focusedplayer);
    void setConterCag(ranger *ranger);
    ranger * getConterCag();
    int getNbGoal();
    void setNbGoal(int nbGoal);
    void initialisesquad(int i);
    player* getReceiverOfBall();
    char getName();
    void setName(char name);


private:
    int m_nbGoal;
    ranger *m_Conterranger;
    QPixmap *m_tabPixplayer[8];
    player *m_defender;
    player *m_striker;
    player *m_goalKeeper;
    player *m_focusedplayer;
    QString m_squad[3];
    char m_name;
};

#endif // squad_H
