#include "AirCraft.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./plane_logo.png"));
    AirCraft w;
    w.show();
    return a.exec();
}
