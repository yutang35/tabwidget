#include <QApplication>
#include "tabwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tabwidget w;
    w.show();
    return a.exec();
}
