#include "machinaG.h"
#include "Mojave.h"
#include "machinaK.h"
#include "QDebug"

machinaG::machinaG(kernel *kernel)
{

    this->m_kernel=kernel;
    m_Mojave=new Mojave();
    this->setMojave(m_Mojave);
    this->setFocusPolicy(Qt::StrongFocus);
    this->scale(0.8,0.71);
    startTimer(32);

}

Mojave * machinaG::getMojave(){
    return this->m_Mojave;
}

void machinaG::setEngineMojave(Mojave * Mojave){
    this->m_Mojave=Mojave;
}

void machinaG::timerEvent(QTimerEvent * event){
    this->m_kernel->getmachinaK()->TimeEvent(event);
}


void machinaG::keyPressEvent(QKeyEvent *event){
 this->m_kernel->getmachinaK()->pressEvent(event);
}

void machinaG::keyReleaseEvent(QKeyEvent *event){
 this->m_kernel->getmachinaK()->releaseEvent(event);
}
