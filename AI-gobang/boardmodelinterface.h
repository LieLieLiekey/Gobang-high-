#ifndef BOARDMODELINTERFACE_H
#define BOARDMODELINTERFACE_H
#include "position.h"
#include "ChessColorPro.h"
#include <string>
#include "chesser.h"
class Chesser;
class BoardModelInterface
{
public:
    BoardModelInterface();
    virtual bool hasChess(Position)=0;
    virtual ChessColorPro getChessColor(Position)=0;
    virtual bool is_gameOver()=0;
    virtual ChessColorPro whoWin()=0;
    virtual ChessColorPro getNowColor()=0;
    virtual std::string getNowName()=0;
    virtual bool putChess(Position,ChessColorPro)=0;
    virtual int getBoardSize()=0;
    virtual std::string getBlackName()=0;
    virtual std::string getWhitename()=0;
    virtual Chesser * getNowChesser()=0;
    virtual bool is_DogFall()=0;
};

#endif // BOARDMODELINTERFACE_H
