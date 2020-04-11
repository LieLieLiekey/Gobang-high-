#ifndef BOARDMODEL_H
#define BOARDMODEL_H
#include "boardmodelinterface.h"
#include "observable.h"
#include "ChessColorPro.h"
#include "chesser.h"
class BoardModelInterface;
class Observable;
class BoardModel : public BoardModelInterface,public Observable
{
public:
    BoardModel(Chesser *black_chesser,Chesser *white_chesser);
    BoardModel(const BoardModel & other);
    bool hasChess(Position) override;
    ChessColorPro getChessColor(Position) override;
    bool is_gameOver() override;
    ChessColorPro whoWin() override;
    ChessColorPro getNowColor() override;
    std::string getNowName() override;
    bool putChess(Position,ChessColorPro) override;
    int getBoardSize() override;
    bool is_DogFall() override;
    std::string getBlackName() override;
    std::string getWhitename() override;
    Chesser * getNowChesser() override ;
private:

    static constexpr int BOARD_SIZE=17;
    ChessColorPro board[BOARD_SIZE+1][BOARD_SIZE+1];
    int now_chesser;
    int alcount;
    Chesser * chessers[2];
    void initBoard();
    ChessColorPro s_getColor(Position );//带check的函数
//    typedef enum {BLACK=ChessColorPro::BLACK,WHITE=ChessColorPro::WHITE,DOGFALL=-1,NOWIN=0} WinFlags;//wait
//    WinFlags winflag; //胜利相关的标志
    using WinFlags= enum {BLACK=ChessColorPro::BLACK,WHITE=ChessColorPro::WHITE,DOGFALL=-1,NOWIN=0};//wait
    WinFlags winflag; //胜利相关的标志
    static bool isgoodpos(Position pos);
};

#endif // BOARDMODEL_H
