#ifndef SHOWINFOFRAME_H
#define SHOWINFOFRAME_H
#include "observer.h"
#include <QString>
#include <QDebug>
#include <QFrame>
#include <QLabel>
#include <QTimer>
#include <QGridLayout>
class ShowInfoFrame:public QFrame
{
public:
    ShowInfoFrame(int width,int height,QString whitename,QString blackname,int alltime);
    void begin();
    ~ShowInfoFrame();
private:
    void setBackgroundImage(const QString & filename);
    void setBackgroundColor(QWidget*,QColor t);
    QLabel *title[2];
    QLabel *name[2];
    QLabel *residue_label[2];
    int residue_time[2];
    QTimer *timers[2];
    QGridLayout *layout;
    static constexpr int BLACK_INDEX=0;
    static constexpr int WHITE_INDEX=1;
//    QLabel *white_name,*black_name;
//    QLabel *white_residue_time,*black_redidue_time;
//    QTimer *white_timer,*black_timer;
};

#endif // SHOWINFOFRAME_H
