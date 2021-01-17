
#ifndef LegionScore_H
#define LegionScore_H
#include <QLCDNumber>

class LegionScore : public QLCDNumber
{
public:
    LegionScore();
    int setButsquad1();
    int setButsquad2();
private:
   int m_Butsquad1;
   int m_Butsquad2;
};

#endif // LegionScore_H
