#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
        void paintEvent(QPaintEvent *event);
        void NewGame();
        void keyPressEvent(QKeyEvent *);
private:
        Ui::MainWindow *ui;
        #define EDGE 4//方块长宽个数
        #define WINWIDTH 500//窗口宽度
        #define WINHEIGHT 600//窗口高度
        int Game[EDGE][EDGE];
        int TempGame[EDGE][EDGE];
        void GoUp();
        void GoDown();
        void GoLeft();
        void GoRight();
        void NewBlock();
        void setTempGameArray();
        bool ifArraySame();
        void setGameArray();
        bool ifWin();
        void MoveSound();
        void WarningSound();
        bool ifFail();
        void FailMessage();
        bool ifFull();
        void timerEvent(QTimerEvent *);
};

#endif // MAINWINDOW_H
