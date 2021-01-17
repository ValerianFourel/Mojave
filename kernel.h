#ifndef kernel_H
#define kernel_H

class machinaK;
class machinaG;
class machinaP;
class kernel
{
public:
    kernel();

    void updateGraphics();

    machinaG *getmachinaG();
    machinaP *getmachinaP();
    machinaK *getmachinaK();
    void run();

private:
    machinaG * m_machinaG;
    machinaP * m_machinaP;
    machinaK * m_machinaK;

};

#endif // kernel_H
