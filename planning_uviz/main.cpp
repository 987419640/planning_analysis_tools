#include "planning_uviz.h"
#include "planning_uviz_interface.h"

#include <QApplication>

#define ENABLE_UVIZ (1)

#if ENABLE_UVIZ
int planning_uviz_main(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    QApplication a(argc, argv);
    planningUviz w;
    w.show();
    return a.exec();
}
