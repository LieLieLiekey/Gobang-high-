#include "showinfoframe.h"
#include <QGridLayout>
#include <QColor>
#include <QPainter>
ShowInfoFrame::ShowInfoFrame(int width,int height,QString whitename,QString blackname,int alltime):QFrame()
{
    setFixedSize(width,height);
    QFrame *tmp=new QFrame(this);
    tmp->setFixedSize(width,height/2);
    layout=new QGridLayout(this);
//    layout->setFixedSize(width,height/2);

    QFont ft;/*
    ft.setPointSize(12);*/
    tmp->setLayout(layout);

    title[BLACK_INDEX] = new QLabel(this);
    title[BLACK_INDEX]->setText("BLACK");
    setBackgroundColor(title[BLACK_INDEX],QColor(255,255,255,255));
//    title[BLACK_INDEX]->setFixedSize(300,100);
    name[BLACK_INDEX] = new QLabel(this);
    name[BLACK_INDEX]->setText(blackname);
    residue_time[BLACK_INDEX]=alltime;
    residue_label[BLACK_INDEX] = new QLabel(this);
    residue_label[BLACK_INDEX]->setText(QString::number(alltime));
    timers[BLACK_INDEX] = new QTimer(this);
    //timers[BLACK_INDEX]->start(1000);
    connect(timers[BLACK_INDEX],&QTimer::timeout,[&]{

            residue_time[BLACK_INDEX]--;
            residue_label[BLACK_INDEX]->setText(QString::number(residue_time[BLACK_INDEX]));
            if(residue_time[BLACK_INDEX] <= 0){
                timers[BLACK_INDEX]->stop();
            }
    });
    layout->addWidget(title[BLACK_INDEX],0,1);
    layout->addWidget(name[BLACK_INDEX],1,1);
    layout->addWidget(residue_label[BLACK_INDEX],2,1);


    title[WHITE_INDEX] = new QLabel(this);
    title[WHITE_INDEX]->setText("WHITE");

    setBackgroundColor(title[WHITE_INDEX],QColor(255,255,255,255));
//    title[WHITE_INDEX]->setFixedSize(300,100);

    name[WHITE_INDEX] = new QLabel(this);
    name[WHITE_INDEX]->setText(whitename);
    residue_time[WHITE_INDEX]=alltime;
    residue_label[WHITE_INDEX] = new QLabel(this);
    residue_label[WHITE_INDEX]->setText(QString::number(alltime));
    timers[WHITE_INDEX] = new QTimer(this);
//    timers[WHITE_INDEX]->start(1000);

    connect(timers[WHITE_INDEX],&QTimer::timeout,[&]{
            residue_time[WHITE_INDEX]--;
            residue_label[WHITE_INDEX]->setText(QString::number(residue_time[WHITE_INDEX]));
            if(residue_time[WHITE_INDEX] <= 0){
                timers[WHITE_INDEX]->stop();
            }
    });
    layout->addWidget(title[WHITE_INDEX],0,2);
    layout->addWidget(name[WHITE_INDEX],1,2);
    layout->addWidget(residue_label[WHITE_INDEX],2,2);

//    layout->addWidget(new QLabel("Color:",this),0,0);
//    layout->addWidget(new QLabel("Name:",this),1,0);
//    layout->addWidget(new QLabel("Residue time(s):",this),2,0);
    setBackgroundColor(this,QColor(153,205,239,255));
//    setBackgroundImage(":/png/image/board.png");
}
//void ShowInfoFrame::setTitle(int index,int )
//{

//}
//void  ShowInfoFrame::setName()
//{

//}
//void ShowInfoFrame:: setTimerInfo()
//{

//}
void ShowInfoFrame::begin()
{
    timers[BLACK_INDEX]->start(1000);
    timers[WHITE_INDEX]->start(1000);
    show();
}
ShowInfoFrame::~ShowInfoFrame()
{

}
void ShowInfoFrame::setBackgroundColor(QWidget *w,QColor t)
{
    QPalette pal(w->palette());
    pal.setColor(QPalette::Background,t); //设置背景黑色
    w->setAutoFillBackground(true);
    w->setPalette(pal);
}

void ShowInfoFrame::setBackgroundImage(const QString & filename)
{
    QPixmap pixmap = QPixmap(filename).scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
}
