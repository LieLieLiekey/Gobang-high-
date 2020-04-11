#ifndef BOARDFRAME_H
#define BOARDFRAME_H
#include <QFrame>
#include <QDebug>
#include <QPixmap>
#include <QImage>
#include "position.h"
#include "ChessColorPro.h"
#include "observer.h"
#include "controlinterface.h"
#include "boardmodelinterface.h"
/* 显示图像，可以设置尺寸
 * 接口函数：
 * 构造函数，但需要主动对之进行注册
 * 双击函数未完成
*/
class Control;
class BoardModelInterface;
class BoardFrame:public QFrame ,public Observer
{
public:
        BoardFrame(BoardModelInterface *_boardmodel=nullptr, ControlInterface *_control=nullptr,int board_pixlength=550,int board_size=17);
//    BoardFrame(int board_pixlength=550,int board_size=17,
//               QImage blackImage=QImage(QString(":/png/image/black.png")),
//               QImage whiteImage=QImage(QString(":/png/image/white.png")),
//               const QString &backgroud_path=":/png/image/board.png");
    void receiveMessage(Observable *) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void drawChess(Position arrpos,ChessColorPro chesscolor);//在棋盘位置画一个棋子
    ~BoardFrame();
private:
    void clean();
    void initAndDrawAll();
//    void init();
    Position scrToarrpos(Position scrpos);//屏幕坐标转换为数组做坐标 错误坐标则返回-1，-1
    Position arrToscrpos(Position arrpos);//数组转化为屏幕中心坐标
    void paintEvent(QPaintEvent *event) override;//paint 事件
    void initPixmap(QPixmap *pixmap);//初始化棋盘的PixMap
    void initChessImage(QImage *);//将一个棋子图像调整为对应的比例
    void setBackgroundImage(const QString & filename);
    void drawTempChess(Position );
private:
    QPixmap *pixmap;
    QImage *black,*white;
    int board_pixlength,board_size,grid_length,hit_range,chess_r ;
    BoardModelInterface *boardmodel;
    ControlInterface *control;
    bool isnpos(const Position & pos);
};

#endif // BOARDFRAME_H
