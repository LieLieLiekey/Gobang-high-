#ifndef CHESSERMAN_H
#define CHESSERMAN_H
#include "chesser.h"
class BoardModelInterface;
class ChesserMan : public Chesser
{
public:
    ChesserMan(std::string _name, ChessColorPro _color);
    virtual bool putChess(BoardModelInterface *,Position & pos) override;
    ~ChesserMan();
};

#endif // CHESSERMAN_H
