#ifndef SHOWINFOFRAMEUI_H
#define SHOWINFOFRAMEUI_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QTimer>
#include "observer.h"
#include "controlinterface.h"
#include "boardmodelinterface.h"
#include <QToolButton>
namespace Ui {
class ShowInfoFrameUi;
}

class ShowInfoFrameUi : public QWidget,public Observer
{
    Q_OBJECT

public:
    explicit ShowInfoFrameUi(ControlInterface *_control,BoardModelInterface *_boardmodel,QString blackname,QString whitename,int alltime,int width=300,int height=550,QWidget *parent=nullptr );
    void begin();
    void receiveMessage(Observable *) override;
    ~ShowInfoFrameUi();

private:
    Ui::ShowInfoFrameUi *ui;
    void setBackgroundImage(const QString & filename);
    void setBackgroundColor(QWidget*,QColor t);
    QLabel *title[2];
    QLabel *name[2];
    QLabel *residue_label[2];
    int residue_time[2];
    QTimer *timers[2];
    QWidget * frame;
    BoardModelInterface *boardmodel;
    ControlInterface *control;
    QToolButton *exit_bt,*giveup_bt;
    static constexpr int BLACK_INDEX=0;
    static constexpr int WHITE_INDEX=1;
    static constexpr int TIME_INTERVAL=1000;
};

//class ShowInfoFrame:public QFrame
//{
//public:
//    ShowInfoFrame(int width,int height,QString whitename,QString blackname,int alltime);
//    void begin();
//    ~ShowInfoFrame();
//private:
//    void setBackgroundImage(const QString & filename);
//    void setBackgroundColor(QWidget*,QColor t);
//    QLabel *title[2];
//    QLabel *name[2];
//    QLabel *residue_label[2];
//    int residue_time[2];
//    QTimer *timers[2];
//    QGridLayout *layout;
//    static constexpr int BLACK_INDEX=0;
//    static constexpr int WHITE_INDEX=1;
////    QLabel *white_name,*black_name;
////    QLabel *white_residue_time,*black_redidue_time;
////    QTimer *white_timer,*black_timer;
//};
#endif // SHOWINFOFRAMEUI_H
