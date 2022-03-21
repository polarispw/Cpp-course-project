#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setFixedSize(320,480);
    w.setWindowTitle("2048小游戏");
    w.show();
    return a.exec();
}
