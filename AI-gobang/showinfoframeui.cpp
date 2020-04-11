#include "showinfoframeui.h"
#include "ui_showinfoframeui.h"
#include <QTimer>

ShowInfoFrameUi::ShowInfoFrameUi(ControlInterface *_control,BoardModelInterface *_boardmodel,QString blackname,QString whitename,int alltime,int width,int height,QWidget *parent ) :
    QWidget(parent),
    ui(new Ui::ShowInfoFrameUi)
{
    ui->setupUi(this);
    this->setFixedSize(width,height);
//    exit_bt=
    this->control=_control;
    this->boardmodel=_boardmodel;
    this->exit_bt=ui->exit_button;
    this->giveup_bt=ui->giveup_button;

    connect(exit_bt,&QToolButton::clicked,[=](){
           control->exitSignal(ChessColorPro::NOCHESS);
    });
    connect(giveup_bt,&QToolButton::clicked,[=](){
        control->giveUpSignal(ChessColorPro::NOCHESS);
    });

    title[BLACK_INDEX]=ui->black_title;
    name[BLACK_INDEX]=ui->black_name;
    residue_label[BLACK_INDEX]=ui->black_redisdue;

    name[BLACK_INDEX]->setText(blackname);
    residue_time[BLACK_INDEX]=alltime;
    residue_label[BLACK_INDEX]->setText(QString::number(alltime)+" s");
    timers[BLACK_INDEX] = new QTimer(this);
    connect(timers[BLACK_INDEX],&QTimer::timeout,[&]{

            residue_time[BLACK_INDEX]--;
            residue_label[BLACK_INDEX]->setText(QString::number(residue_time[BLACK_INDEX])+ " s");
            if(residue_time[BLACK_INDEX] <= 0){
                timers[BLACK_INDEX]->stop();
                control->timeOutSingal(ChessColorPro::NOCHESS);
            }
    });

    title[WHITE_INDEX]=ui->white_title;
    name[WHITE_INDEX]=ui->white_name;
    residue_label[WHITE_INDEX]=ui->white_residue;

    name[WHITE_INDEX]->setText(whitename);
    residue_time[WHITE_INDEX]=alltime;
    residue_label[WHITE_INDEX]->setText(QString::number(alltime)+" s");
    timers[WHITE_INDEX] = new QTimer(this);
    connect(timers[WHITE_INDEX],&QTimer::timeout,[&]{

            residue_time[WHITE_INDEX]--;
            residue_label[WHITE_INDEX]->setText(QString::number(residue_time[WHITE_INDEX])+" s");
            if(residue_time[WHITE_INDEX] <= 0){
                timers[WHITE_INDEX]->stop();
                control->timeOutSingal(ChessColorPro::NOCHESS);
            }
    });

}
void ShowInfoFrameUi::receiveMessage(Observable *)
{
        int nowindex=(boardmodel->getNowColor()==ChessColorPro::BLACK)?BLACK_INDEX:WHITE_INDEX;
        timers[nowindex]->start(TIME_INTERVAL);
        int oppindex=nowindex==BLACK_INDEX?WHITE_INDEX:BLACK_INDEX;
        timers[oppindex]->stop();
}
void ShowInfoFrameUi::begin()
{
//    timers[BLACK_INDEX]->start(TIME_INTERVAL);
//    timers[WHITE_INDEX]->start(TIME_INTERVAL);
    show();
}
ShowInfoFrameUi::~ShowInfoFrameUi()
{
    delete ui;
}
