#include "mainwindow.h"
#include "instruction.h"
#include "welcome.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcome s;
    s.show();

    return a.exec();
}
