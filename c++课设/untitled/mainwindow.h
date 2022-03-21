#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPushButton>
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);

    void PressUp();
    void PressDown();
    void PressLeft();
    void PressRight();
    void myRand();

    QPushButton *button;
    int s[4][4];
    int score=0;
    bool state;

    struct Ns{
        int i;
        int j;
    };
public slots:
    void slotStart();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
