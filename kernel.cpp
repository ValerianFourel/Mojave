#include "kernel.h"
#include "machinaG.h"
#include "machinaP.h"
#include "machinaK.h"
#include "player.h"
#include "squad.h"


kernel::kernel()
{
    m_machinaG=new machinaG(this);
    m_machinaP=new machinaP(this);
    m_machinaK=new machinaK(this);
}

void kernel::updateGraphics(){

}

machinaG * kernel::getmachinaG(){
    return this->m_machinaG;
}

machinaP * kernel::getmachinaP(){
    return this->m_machinaP;
}

machinaK * kernel::getmachinaK(){
    return this->m_machinaK;
}

void kernel::run(){
    this->m_machinaG->showFullScreen();

}
