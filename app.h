#ifndef app_H
#define app_H
#include <Qapp>

class kernel;
class app : public Qapp
{
private:
    kernel *m_kernel;
public:
    app(int argc, char **argv);
    int  main();
};

#endif // app_H
