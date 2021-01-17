#include "LegionScore.h"

LegionScore::LegionScore()
{
    this->m_Butsquad1 = 0;
    this->m_Butsquad2 = 0;
}


//---Method that increments goals for squad1---
int LegionScore::setButsquad1()
{
    return this->m_Butsquad1 = this->m_Butsquad1 +1;
}

//---Method that increments goals for squad2---
int LegionScore::setButsquad2()
{
    return this->m_Butsquad2 = this->m_Butsquad2 +1;
}
