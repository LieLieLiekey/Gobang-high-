#include "boardmodel.h"

//BoardModel::BoardModel()
//{

//}
BoardModel::BoardModel(Chesser *black_chesser,Chesser *white_chesser):BoardModelInterface(),Observable()
{
    /*empty*/
    chessers[0]=black_chesser;
    chessers[1]=white_chesser;
    this->now_chesser=0;
    this->alcount=0;

    this->winflag=WinFlags::NOWIN;
    initBoard();
}
/*
    static constexpr int BOARD_SIZE=17;
    ChessColorPro board[BOARD_SIZE+1][BOARD_SIZE+1];
    int now_chesser;
    int alcount;
    Chesser * chessers[2];
    void initBoard();
    ChessColorPro s_getColor(Position );//带check的函数
    typedef enum WinFlags {BLACK=ChessColorPro::BLACK,WHITE=ChessColorPro::WHITE,DOGFALL=-1,NOWIN=0};//wait
*/
Chesser* BoardModel::getNowChesser()
{
    return chessers[now_chesser];
}
BoardModel::BoardModel(const BoardModel & other)
{
    int size=getBoardSize();
    for(int i=1;i<=size;++i){
        for(int j=1;j<=size;++j){
               this->board[i][j]=other.board[i][j];
        }
    }
    this->chessers[0]=other.chessers[0];
    this->chessers[1]=other.chessers[1];
    this->now_chesser=other.now_chesser;
    this->alcount=other.alcount;
    this->winflag=other.winflag;

}
void BoardModel::initBoard()
{
    for(int i=1;i<=BOARD_SIZE;++i)
        for(int j=1;j<=BOARD_SIZE;++j){
            board[i][j]=ChessColorPro::NOCHESS;
        }
}
ChessColorPro BoardModel::s_getColor(Position pos)
{
    if(pos.x>=1 && pos.x<=BOARD_SIZE &&pos.y >=1 && pos.y<=BOARD_SIZE)
        return board[pos.x][pos.y];
    else
        return ChessColorPro::OUTRANGE;
}

bool BoardModel::isgoodpos(Position pos)// no use
{
    if(pos.x>=1 && pos.x<=BOARD_SIZE &&pos.y >=1 && pos.y<=BOARD_SIZE)
        return true;
    else
        return false;
}
bool BoardModel::hasChess(Position pos)
{
    ChessColorPro res=s_getColor(pos);
    if(res == ChessColorPro::WHITE || res == ChessColorPro::BLACK)
            return true;
    else return false;
}
ChessColorPro BoardModel::getChessColor(Position pos)
{
     return s_getColor(pos);
}
bool BoardModel::is_gameOver()
{
    if(winflag != WinFlags::NOWIN){
        return true;
    }
    int size = getBoardSize();
    if (alcount == size* size)
    {
        winflag=WinFlags::DOGFALL;
        return true;//平局
    }
    int cnt;
    for (int i = 1; i <= size; ++i)
    {
        for (int j = 1; j <= size; ++j)
        {
            if (board[i][j]==ChessColorPro::NOCHESS)
                continue;
            cnt = 1;
            for (int k = i - 4; k<i&&k >= 1; k++)
            {
                if (board[k][j] == board[i][j])
                    cnt++;
                else
                    break;
            }
            if (cnt == 5)
            {
                winflag=(board[i][j]==ChessColorPro::BLACK)?WinFlags::BLACK : WinFlags::WHITE ;
                return true;
            }
            //竖直方向
            cnt = 1;
            for (int k = j - 4; k >= 1 && k<j; k++)
            {
                if (board[i][k] == board[i][j])
                    cnt++;
                else
                    break;
            }
            if (cnt == 5)
            {
                winflag=(board[i][j]==ChessColorPro::BLACK)?WinFlags::BLACK : WinFlags::WHITE ;
                return true;
            }
            //水平方向
            cnt = 1;
            for (int x = i - 4, y = j - 4; x >= 1 && y >= 1 && x<i&&y<j; x++, y++)
            {
                if (board[x][y] == board[i][j])
                    cnt++;
                else
                    break;
            }
            if (cnt == 5)
            {
                winflag=(board[i][j]==ChessColorPro::BLACK)?WinFlags::BLACK : WinFlags::WHITE ;
                return true;
            }
            //左上方向
            cnt = 1;
            for (int x = i - 4, y = j + 4; x >= 1 && x<i&&y <= size && y>j; ++x, --y)
            {
                if (board[x][y] == board[i][j])
                    cnt++;
                else
                    break;
            }
            if (cnt == 5)
            {
                winflag=(board[i][j]==ChessColorPro::BLACK)?WinFlags::BLACK : WinFlags::WHITE ;
                return true;
            }
            //右斜方向
        }
    }
    return false;
}
bool BoardModel::is_DogFall()
{
    if(winflag == WinFlags::DOGFALL)
        return true;
    else{
        is_gameOver();
        return winflag == WinFlags::DOGFALL;
    }
}
ChessColorPro BoardModel::whoWin()
{
    switch (winflag)
    {
        case WinFlags::BLACK:
            return ChessColorPro::BLACK;
        case WinFlags::WHITE:
            return ChessColorPro::WHITE;
        default:
            return ChessColorPro::NOCHESS;
    }
}
ChessColorPro BoardModel::getNowColor()
{
    return chessers[now_chesser]->getColor();
}
std::string BoardModel::getNowName()
{
    return chessers[now_chesser]->getName();
}
bool  BoardModel::putChess(Position pos,ChessColorPro color)
{
    if(pos.x>=1 && pos.x<=BOARD_SIZE &&pos.y >=1 && pos.y<=BOARD_SIZE && !hasChess(pos) ){
      if(winflag!=WinFlags::NOWIN) return false;

      board[pos.x][pos.y] = color;

      now_chesser^=1;//切换下标

      ++alcount;
      notifyObservers();
      return true;
    }
    else return false;

}
int BoardModel::getBoardSize()
{
    return BOARD_SIZE;
}
std::string BoardModel::getBlackName()
{
    if(chessers[0]->getColor() == ChessColorPro::BLACK)
        return chessers[0]->getName();
    else return chessers[1]->getName();
}
std::string BoardModel::getWhitename()
{
    if(chessers[0]->getColor() == ChessColorPro::WHITE)
        return chessers[0]->getName();
    else return chessers[1]->getName();
}
