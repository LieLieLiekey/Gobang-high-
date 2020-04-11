#include "boardframe.h"
#include <QDebug>
#include <QPainter>
#include <QPoint>
#include <QRect>
BoardFrame::BoardFrame(BoardModelInterface *_boardmodel, ControlInterface *_control,int board_pixlength,int board_size):QFrame(),Observer()
{
//    QImage blackImage=QImage(QString(":/png/image/black.png")),
//    QImage whiteImage=QImage(QString(":/png/image/white.png")),
//    const QString &backgroud_path=":/png/image/board.png"
    //blackImage,Whiteimage 未处理
    this->board_pixlength= board_pixlength;
    this->board_size=board_size;
    this->black = new QImage(QString(":/png/image/black.png"));
    this->white = new QImage(QString(":/png/image/white.png")),
    this->grid_length = board_pixlength / board_size;
    this->hit_range = grid_length / 3;//点击中心的半径有效
    this->chess_r = grid_length / 3; // 棋子的半径
    this->pixmap=new QPixmap;
    this->boardmodel=_boardmodel;
    this->control=_control;
    setBackgroundImage(":/png/image/board.png");
    initChessImage(this->black);
    initChessImage(this->white);
    setFixedSize(board_pixlength,board_pixlength);
    initPixmap(pixmap);
}
void BoardFrame::initAndDrawAll()
{
    initPixmap(pixmap);
    int size=boardmodel->getBoardSize();
    for(int i=1;i<=size;++i){
            for(int j=1;j<=size;++j){
                if(boardmodel->hasChess(Position(i,j)))
                {
                       drawChess(Position(i,j),boardmodel->getChessColor(Position(i,j)));
                }
            }
    }
}
void BoardFrame::receiveMessage(Observable * )
{
    initAndDrawAll();
    update();
}
void BoardFrame::mousePressEvent(QMouseEvent *event)
{
    Position srcpos=Position(event->x(),event->y());
//    qDebug() << "单击: x :"<<event->x()<<" y:"<<event->y()<<" \n";
    Position arrpos=scrToarrpos(srcpos);
    if(isnpos(arrpos)) return;
    else{
        if(! boardmodel->hasChess(arrpos)){
               //put a temp
            initAndDrawAll();
            drawTempChess(arrpos);
            update();
            //qDebug() << " temp Positon: x:"<<arrpos.x <<" y:" << arrpos.y<<"\n";
        }
    }
}
void BoardFrame::mouseDoubleClickEvent(QMouseEvent *event)
{
    Position srcpos=Position(event->x(),event->y());
//    qDebug() << "双击: x :"<<event->x()<<" y:"<<event->y()<<" \n";
    Position arrpos=scrToarrpos(srcpos);
    if(isnpos(arrpos)) return;
    else{
        if(! boardmodel->hasChess(arrpos)){
            control->putChessSignal(arrpos);
//            qDebug() << " ready putchess Positon: x:"<<arrpos.x <<" y:" << arrpos.y<<"\n";
        }
    }
}
void BoardFrame::drawTempChess(Position  pos)
{
      QPainter painter(pixmap);
      painter.setPen(QColor(255,255,255,255));
      Position srcpos=arrToscrpos(pos);
      painter.drawEllipse(QPoint(srcpos.x,srcpos.y),chess_r,chess_r);

//                  QRect(QPoint(srcpos.x-chess_r,srcpos.y-chess_r),QPoint(srcpos.x+chess_r,srcpos.y+chess_r)));
      painter.end();
}
bool BoardFrame::isnpos(const Position & pos)
{
    if(pos.x>=1 && pos.x<=board_size &&pos.y >=1 && pos.y<=board_size)
        return false;
    else
        return true;
}
void BoardFrame::setBackgroundImage(const QString & filename)
{
    QPixmap pixmap = QPixmap(filename).scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}

void BoardFrame::initChessImage(QImage *image)
{
    *image = image->scaled(chess_r*2,chess_r*2);

}
void BoardFrame::initPixmap(QPixmap *pixmap)
{
    /*
        将pixmap整成棋盘图像
    */
    *pixmap = QPixmap(board_pixlength,board_pixlength);
     pixmap->fill(QColor(213, 181, 55,0));//backgroud of pixmap  is lucenc
     QPainter painter(pixmap);
     painter.setPen(QColor(0, 0, 0));//line is black
     {//画上所有横线
         int x1, x2;
         x1 = grid_length / 2, x2 = x1+grid_length*(board_size-1);
 //        x1 = grid_length / 2, x2 = board_pixlength - x1;
         int y = -x1;
         for (int i = 0; i < board_size; ++i)
         {
             y += grid_length;
             painter.drawLine(QPoint(x1, y),QPoint(x2, y));
         }
     }
     {
         int x, y1, y2;
         y1 = grid_length / 2, y2 = y1+grid_length*(board_size-1);
         x = -y1;
         for (int i = 0; i < board_size; ++i)
         {
             x += grid_length;
             painter.drawLine(QPoint(x, y1),QPoint(x, y2));
         }
     }
     painter.end();
}

Position BoardFrame::scrToarrpos(Position scrpos)//屏幕坐标转换为数组做坐标 错误坐标则返回-1，-1
{
    /*
        注意：无效坐标的处理，可能耦合度太高
    */
    int xline, mod_x;
    int yline, mod_y;
    mod_x = scrpos.x % grid_length;
    xline = scrpos.x / grid_length;
    mod_y = scrpos.y % grid_length;
    yline = scrpos.y / grid_length;
    if ((mod_x >= (grid_length / 2 - hit_range) && mod_x <= (grid_length / 2 + hit_range)) &&(mod_y >= (grid_length / 2 - hit_range) && mod_y <= (grid_length / 2 + hit_range)))
        return Position(xline + 1,yline + 1);
    else
         return Position(-1, -1);
}

Position BoardFrame::arrToscrpos(Position arrpos)//数组转化为屏幕中心坐标
{
    int x = arrpos.x;
    int y = arrpos.y;
    int scrx, scry;
    scrx = grid_length / 2 + (x - 1)*grid_length;
    scry = grid_length / 2 + (y - 1)*grid_length;
    return Position(scrx,scry);

}
void BoardFrame::drawChess(Position arrpos,ChessColorPro chesscolor)//
{
    Position srcpos=arrToscrpos(arrpos);
    int x1=srcpos.x-chess_r,y1=srcpos.y - chess_r;
    QPainter painter(pixmap);
    if(chesscolor == ChessColorPro::BLACK)
    {
        painter.drawImage(QPoint(x1,y1),*black);
    }
    else if(chesscolor == ChessColorPro::WHITE)
    {
        painter.drawImage(QPoint(x1,y1),*white);
    }
    else{
        qDebug() << "ChessColor error.\n";
        throw chesscolor;
    }
}
//void BoardFrame::init()
//{
//    QPainter painter(pixmap);
//    painter.setPen(QColor(128, 0, 0));
//    {//画上所有横线
//        int x1, x2;
//        x1 = grid_length / 2, x2 = x1+grid_length*(board_size-1);
//        int y = -x1;
//        for (int i = 0; i < board_size; ++i)
//        {
//            y += grid_length;
//            painter.drawLine(QPoint(x1, y),QPoint(x2, y));
//        }
//    }
//    {
//        int x, y1, y2;
//        y1 = grid_length / 2, y2 = y1+grid_length*(board_size-1);
//        x = -y1;
//        for (int i = 0; i < board_size; ++i)
//        {
//            x += grid_length;
//            painter.drawLine(QPoint(x, y1),QPoint(x, y2));
//        }
//    }
//    painter.end();
//}
void BoardFrame::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(QRect(0,0,width(),height()),*pixmap);
    painter.end();
   // painter.drawPixmap(width(),height(),pixmap);
}
void BoardFrame::clean()
{

}
BoardFrame::~BoardFrame()
{
    delete pixmap;
    delete black;
    delete white;
}
