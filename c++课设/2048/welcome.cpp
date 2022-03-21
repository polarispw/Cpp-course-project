#include "welcome.h"
#include "instruction.h"
#include "ui_welcome.h"
#include "mainwindow.h"
#include <QPainter>
welcome::welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
    this->setFixedSize(WINWIDTH,WINHEIGHT);
    this->setWindowIcon(QPixmap(":/game/image/Icon.png"));
    this->setWindowTitle("2048");
}

welcome::~welcome()
{
    delete ui;
}

void welcome::on_pushButton_clicked()
{
  MainWindow *mainwindow=new MainWindow;
  this->close();
  mainwindow->show();
}

void welcome::on_pushButton_2_clicked()
{
    instruction *w=new instruction;
    this->close();
    w->show();
}
void welcome::paintEvent(QPaintEvent *event){
    //绘制背景
    //绘制方块底色
    QPainter painter(this);
    QPixmap bgpix,blockBGPix,Icon2048;
    bgpix.load(":/game/image/BGPic.png");
    Icon2048.load(":/game/image/2048.png");
    blockBGPix.load(":/game/image/blockBGPix.png");
    painter.drawPixmap(0,0,WINWIDTH,WINHEIGHT,bgpix);
    painter.drawPixmap((WINWIDTH-400)/2,(WINHEIGHT-400)/2,400,400,blockBGPix);
    painter.drawPixmap(200,30,100,60,Icon2048);

    //绘制步数与时间s
    ui->pushButton->setStyleSheet("color: rgb(102,51,51)");
    ui->pushButton_2->setStyleSheet("color: rgb(102,51,51)");
    ui->pushButton->move(205,225);
    ui->pushButton_2->move(205,315);
}
