#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //w.setFixedSize(300, 300);
    w.show();

    return a.exec();
}