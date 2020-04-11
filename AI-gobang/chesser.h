#ifndef CHESSER_H
#define CHESSER_H
#include "ChessColorPro.h"
#include "boardmodelinterface.h"
#include "position.h"
#include <string>
class BoardModelInterface;
class Chesser
{
public:
    Chesser(std::string _name, ChessColorPro _color);
    virtual std::string getName();
    virtual ChessColorPro getColor();
    virtual bool putChess(BoardModelInterface *,Position & pos)=0;
    virtual ~Chesser();
private:
    ChessColorPro color;
    std::string name;
};

#endif // CHESSER_H
