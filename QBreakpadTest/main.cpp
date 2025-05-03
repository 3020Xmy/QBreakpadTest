#include "QBreakpadTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QBreakpadTest w;
    w.show();
    return a.exec();
}
