#ifndef CHESSERAI_H
#define CHESSERAI_H

#include "chesser.h"
class BoardModelInterface;
class ChesserAI : public Chesser
{
public:
    ChesserAI(std::string _name, ChessColorPro _color);
    virtual bool putChess(BoardModelInterface *,Position & pos) override;
    ~ChesserAI();
protected:
    int envaluateAt(Position p, ChessColorPro Who,BoardModelInterface * bd);
    ChessColorPro getChessColor(Position pos, int dir, int offset,BoardModelInterface * bd);//得到一个点某一方方向偏移量的棋色
};

#endif // CHESSERAI_H
