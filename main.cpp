#include <QApplication>
#include "cframe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cframe w;
    w.show();
    return a.exec();
}
