#include "chesser.h"

Chesser::Chesser(std::string _name, ChessColorPro _color)
{
    this->name=_name;
    this->color=_color;
}
std::string Chesser::getName()
{
    return name;
}
ChessColorPro Chesser::getColor()
{
    return color;
}
Chesser::~Chesser()
{

}
