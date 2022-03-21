#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <QPainter>
#include <string.h>
#include <cmath>
#include <QDebug>
#include <QKeyEvent>
#include <iostream>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QTimerEvent>
#define NEWBLOCK rand()%2+1
#define NEWPOINT rand()%EDGE

int Steps,Time,timerId,score=0,tempscore=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(WINWIDTH,WINHEIGHT);
    this->setWindowIcon(QPixmap(":/game/image/Icon.png"));
    this->setWindowTitle("2048");
    connect(ui->action1,&QAction::triggered,[=](){
        NewGame();
        this->update();
    });
    connect(ui->action2,&QAction::triggered,[=](){
        this->close();
    });
    connect(ui->action1_2,&QAction::triggered,[=](){
        QMessageBox::information(this,"游戏说明","按“↑”、“↓”、“←”、“→”操作方块移动");
    });

    NewGame();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NewGame(){
    //归零
    killTimer(timerId);
    timerId=startTimer(1000);
    Steps=0;
    Time=0;
    score=0;
    ui->label->setText("0秒");
    srand((unsigned)time(NULL));
    for(int i=0;i<EDGE;i++)
        for(int j=0;j<EDGE;j++){
            Game[i][j]=0;
        }
    //任意2个方块随机生成2或4
    int x,y;
    for(int i=0;i<2;i++){
        do{
            x=NEWPOINT;
            y=NEWPOINT;
        }while(Game[y][x]);
        Game[y][x]=NEWBLOCK;
    }


}
void MainWindow::NewBlock(){
    srand((unsigned)time(NULL));
    int X,Y;
    do{
       X=NEWPOINT;
       Y=NEWPOINT;
    }while(Game[Y][X]);
    Game[Y][X]=NEWBLOCK;
}
//绘制函数
void MainWindow::paintEvent(QPaintEvent *event){
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
    //绘制方块
    for(int i=0;i<EDGE;i++){
        for(int j=0;j<EDGE;j++){
            char nowPix[30]=":/game/image/block/";
            nowPix[19]=Game[i][j]/10+'0';
            nowPix[20]=Game[i][j]%10+'0';
            strcat(nowPix,".png");
            QPixmap tempPix;
            tempPix.load(nowPix);
            painter.drawPixmap((WINWIDTH-400)/2+j*100+4,(WINHEIGHT-400)/2+i*100+4,92,92,tempPix);
        }
    }

    //绘制游戏信息
    ui->label->setStyleSheet("color: rgb(102,51,51)");
    ui->label_2->setStyleSheet("color: rgb(102,51,51)");
    ui->label_3->setStyleSheet("color: rgb(102,51,51)");
    ui->label_2->setText(QString::number(Steps)+"步");
    ui->label_3->setText(QString::number(score)+"分");
    ui->label->move(50,480);
    ui->label_2->move(225,480);
    ui->label_3->move(400,480);
}
void MainWindow::timerEvent(QTimerEvent *){
    ui->label->setText(QString::number(Time++)+"秒");
}
//移动操作
void MainWindow::keyPressEvent(QKeyEvent *event){
    this->setFocusPolicy(Qt::StrongFocus);
    bool ifMove=false;
    if(event->key()==Qt::Key_Up){
        GoUp();
        ifMove=true;
    }else if(event->key()==Qt::Key_Down){
        GoDown();
        ifMove=true;
    }else if(event->key()==Qt::Key_Left){
        GoLeft();
        ifMove=true;
    }else if(event->key()==Qt::Key_Right){
        GoRight();
        ifMove=true;
    }
    if(ifMove){
        if(!ifArraySame()){
            Steps++;
            setGameArray();//更新方块
            NewBlock();//产生新方块
            this->update();//重新显示
            MoveSound();//播放声音
        }
        else
        {
            WarningSound();//不可移动
        }
        ifFail();
        ifWin();
    }
}
void MainWindow::GoUp(){
    setTempGameArray();
    for(int j=0;j<EDGE;j++){
        bool CheckLine=false;
        //是否需要操作该竖行
        for(int i=0;i<EDGE;i++){
            if(TempGame[i][j]){
                CheckLine=true;
                break;
            }
        }
        if(CheckLine){
            //0沉底
            for(int i=0;i<EDGE;i++){
                if(!TempGame[i][j]){
                    for(int k=i+1;k<EDGE;k++){
                        if(TempGame[k][j]){
                            TempGame[i][j]=TempGame[k][j];
                            TempGame[k][j]=0;
                            break;
                        }
                    }
                }
            }
        }
    }
    //相同的融合
    for(int j=0;j<EDGE;j++){
        for(int i=0;i<EDGE-1;i++){
            if(TempGame[i][j]==TempGame[i+1][j]&&TempGame[i][j]&&TempGame[i+1][j]){
                TempGame[i][j]++;
                tempscore+=pow(2,TempGame[i][j]);
                TempGame[i+1][j]=0;
                //将0沉底
                for(int k=i+1;k<EDGE-1;k++){
                    TempGame [k][j]=TempGame[k+1][j];
                }
                TempGame[EDGE-1][j]=0;
            }
        }
    }

}
void MainWindow::GoDown(){
    setTempGameArray();
    for(int j=0;j<EDGE;j++){
        bool CheckLine=false;
        //是否需要检测该竖行
        for(int i=0;i<EDGE;i++){
            if(TempGame[i][j]){
                CheckLine=true;
                break;
            }
        }
        if(CheckLine){
            //0沉底
            for(int i=EDGE-1;i>=0;i--){
                if(!TempGame[i][j]){
                    for(int k=i-1;k>=0;k--){
                        if(TempGame[k][j]){
                            TempGame[i][j]=TempGame[k][j];
                            TempGame[k][j]=0;
                            break;
                        }
                    }
                }
            }
        }
    }
    //相同的融合
    for(int j=0;j<EDGE;j++){
        for(int i=EDGE-1;i>0;i--){
            if(TempGame[i][j]==TempGame[i-1][j]&&TempGame[i][j]&&TempGame[i-1][j]){
                TempGame[i][j]++;
                tempscore+=pow(2,TempGame[i][j]);
                TempGame[i-1][j]=0;
                //将0沉底
                for(int k=i-1;k>0;k--){
                    TempGame [k][j]=TempGame[k-1][j];
                }
                TempGame[0][j]=0;
            }
        }
    }

}
void MainWindow::GoLeft(){
    //0沉底
    setTempGameArray();
    for(int i=0;i<EDGE;i++){
        bool CheckLine=false;
        for(int j=0;j<EDGE;j++){
            if(TempGame[i][j]){
                CheckLine=true;
                break;
            }
        }
        if(CheckLine){
            for(int j=0;j<EDGE;j++){
                if(!TempGame[i][j]){
                    for(int k=j+1;k<EDGE;k++){
                        if(TempGame[i][k]){
                            TempGame[i][j]=TempGame[i][k];
                            TempGame[i][k]=0;
                            break;
                        }
                    }
                }
            }
        }
    }
    //相同的融合
    for(int i=0;i<EDGE;i++){
        for(int j=0;j<EDGE-1;j++){
            if(TempGame[i][j]==TempGame[i][j+1]&&TempGame[i][j]&&TempGame[i][j+1]){
                TempGame[i][j]++;
                tempscore+=pow(2,TempGame[i][j]);
                TempGame[i][j+1]=0;
                //将0沉底
                for(int k=j+1;k<EDGE-1;k++){
                    TempGame [i][k]=TempGame[i][k+1];
                }
               TempGame[i][EDGE-1]=0;
            }
        }
    }

}
void MainWindow::GoRight(){
    setTempGameArray();
    for(int i=0;i<EDGE;i++){
        bool CheckLine=false;
        //是否需要检测该竖行
        for(int j=0;j<EDGE;j++){
            if(TempGame[i][j]){
                CheckLine=true;
                break;
            }
        }
        if(CheckLine){
            //0沉底
            for(int j=EDGE-1;j>=0;j--){
                if(!TempGame[i][j]){
                    for(int k=j-1;k>=0;k--){
                        if(TempGame[i][k]){
                            TempGame[i][j]=TempGame[i][k];
                            TempGame[i][k]=0;
                            break;
                        }
                    }
                }
            }
        }
    }
    //相同的融合
    for(int i=0;i<EDGE;i++){
        for(int j=EDGE-1;j>0;j--){
            if(TempGame[i][j]==TempGame[i][j-1]&&TempGame[i][j]&&TempGame[i][j-1]){
                TempGame[i][j]++;
                tempscore+=pow(2,TempGame[i][j]);
                TempGame[i][j-1]=0;
                //将0沉底
                for(int k=j-1;k>0;k--){
                    TempGame [i][k]=TempGame[i][k-1];
                }
                TempGame[i][0]=0;
            }
        }
    }
}
//数组更新
void MainWindow::setTempGameArray(){
    tempscore=score;
    for(int i=0;i<EDGE;i++){
        for(int j=0;j<EDGE;j++){
            TempGame[i][j]=Game[i][j];
        }
    }
}
void MainWindow::setGameArray(){
    score=tempscore;
    for(int i=0;i<EDGE;i++){
        for(int j=0;j<EDGE;j++){
            Game[i][j]=TempGame[i][j];
        }
    }
}
bool MainWindow::ifArraySame(){
    bool ifSame=true;
    for(int i=0;i<EDGE&&ifSame;i++){
        for(int j=0;j<EDGE&&ifSame;j++){
            if(Game[i][j]!=TempGame[i][j]){
                ifSame=false;
            }
        }
    }
    return ifSame;
}
//游戏声音
void MainWindow::MoveSound(){
    static QMediaPlayer *player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/game/audio/move.mp3"));
    player->setVolume(30);
    player->play();
}
void MainWindow::WarningSound(){
    static QMediaPlayer *player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/game/audio/warning.mp3"));
    player->setVolume(30);
    player->play();
}
//判断游戏是否继续
bool MainWindow::ifFull(){
    bool full=true;
    for(int i=0;i<EDGE;i++){
        for(int j=0;j<EDGE;j++){
            //只要有一个0则没有满屏
            if(!Game[i][j])
            {
                full=false;
                return full;
            }
        }
    }
    return full;
}
bool MainWindow::ifFail(){
    if(ifFull())
    {
        setTempGameArray();
        bool fail=true;
        //进行一次模拟操作,若数组有变化则表明还有移动的可能
        GoUp();
        if(!ifArraySame()){
            fail=false;
            return fail;
        }
        GoDown();
        if(!ifArraySame()){
            fail=false;
            return fail;
        }
        GoLeft();
        if(!ifArraySame()){
            fail=false;
            return fail;
        }
        GoRight();
        if(!ifArraySame()){
            fail=false;
            return fail;
        }
        if(fail)
        {
            killTimer(timerId);
            QMessageBox::StandardButton ret = QMessageBox::information(this,"END","游戏结束\n用    时:"+QString::number(Time)+"\n步    数:"+QString::number(Steps)+"\n得    分:"+QString::number(score),QMessageBox::Retry,QMessageBox::Close);
            if(ret==QMessageBox::Retry){
                NewGame();
                this->update();
            }
            else if(ret==QMessageBox::Close){
                this->close();
            }
        }
    }
    else
        return false;
}
bool MainWindow::ifWin(){
    bool ifWin=false;
    for(int i=0;i<EDGE;i++){
        for(int j=0;j<EDGE;j++){
            if(Game[i][j]==12){
                ifWin=true;
                i=EDGE;j=EDGE;
            }
        }
    }
    if(ifWin){
        killTimer(timerId);
        QMessageBox::StandardButton ret = QMessageBox::information(this,"END","游戏结束\n用    时:"+QString::number(Time)+"\n步    数:"+QString::number(Steps)+"\n得    分:"+QString::number(score),QMessageBox::Retry,QMessageBox::Close);
        if(ret==QMessageBox::Retry){
            NewGame();
            this->update();
        }else if(ret==QMessageBox::Close){
            this->close();
        }
    }
    return false;
}
