#include "task5.h"
#include <QtWidgets/QApplication>
#include "paintingwidget.h"
#include "paintingrectangle.h"


int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    task5 w;
    w.show();
    return a.exec();
    */
    QApplication a(argc, argv);
    task5 w(nullptr);
    w.resize(800, 600);
    w.show();
    return a.exec();
}
