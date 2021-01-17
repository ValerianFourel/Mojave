#include "app.h"
#include "kernel.h"

app::app(int argc, char * argv[]): Qapp(argc, argv){
//create a kernel and run it
    m_kernel=new kernel();
    m_kernel->run();

}
int main(int argc, char **argv){
    app a(argc,argv);

    return a.exec();
}
