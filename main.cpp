#include "AirCraft.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AirCraft w;
    w.show();
    return a.exec();
}
