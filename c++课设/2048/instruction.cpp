#include "instruction.h"
#include "ui_instruction.h"
#include "welcome.h"
#include <QPainter>
instruction::instruction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instruction)
{
    ui->setupUi(this);
    this->setFixedSize(WINWIDTH,WINHEIGHT);
    this->setWindowIcon(QPixmap(":/game/image/Icon.png"));
    this->setWindowTitle("2048");
}

instruction::~instruction()
{
    delete ui;
}

void instruction::on_pushButton_clicked()
{
    welcome *s=new welcome;
    this->close();
    s->show();
}
void instruction::paintEvent(QPaintEvent *event){
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

    ui->label->setStyleSheet("color: rgb(102,51,51)");
    ui->pushButton->setStyleSheet("color: rgb(102,51,51)");
    ui->label->move(60,150);
    ui->pushButton->move(180,315);
}
