#include "chesserai.h"

ChesserAI::ChesserAI(std::string _name, ChessColorPro _color):Chesser(_name,_color)
{

}
ChesserAI::~ChesserAI()
{

}
bool ChesserAI::putChess(BoardModelInterface * bd,Position & anspos)
{
    /*
        AI下棋思路:
        1.枚举每个空闲位置，假设自己的棋子放上去后，棋盘对自己的优势k，那么求出最大的优势值max1,对应的位置为ansp1
        2.枚举每个空闲位置，假设敌方的棋子放上去后，棋盘对敌方的优势k，那么求出最大的优势值max2，对应的位置为ansp2
        3.if max1 >= max2 下到位置ansp1,否则下到位置ansp2
        注：棋盘对棋手的优势估计函数是envaluateAt,也是AI算法的关键。
    */
    int max1=-1;
    int val;
    Position ansp1, npos, ansp2;
    int size = bd->getBoardSize();
    ChessColorPro self=this->getColor();//自己的颜色
    for(int i=1;i<=size;++i)
        for (int j = 1; j <= size; ++j)
        {
            if (bd->getChessColor(Position(i,j)) != ChessColorPro::NOCHESS)
                continue;
            npos = Position(i, j);
            val = envaluateAt(npos, self,bd);
            if (val > max1)
            {
                ansp1 = npos;
                max1 = val;
            }
        }
    ChessColorPro opposite = (self == ChessColorPro::BLACK) ? ChessColorPro::WHITE : ChessColorPro::BLACK; ////敌方的颜色
    int max2=-1;
    for (int i = 1; i <= size; ++i)
        for (int j = 1; j <= size; ++j)
        {
           if (bd->getChessColor(Position(i,j)) != ChessColorPro::NOCHESS)
                continue;
            npos = Position(i, j);
            val = envaluateAt(npos, opposite,bd);
            if (val > max2)
            {
                ansp2 = npos;
                max2 = val;
            }
        }
    anspos= max1 >= max2 ?ansp1:ansp2;
    return true;
}

ChessColorPro  ChesserAI::getChessColor(Position pos, int dir, int offset,BoardModelInterface * bd)
{
    static int dir_offset[][2]{ {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};
    int r = pos.x;
    int l = pos.y;
    r += dir_offset[dir][0] * offset;
    l += dir_offset[dir][1] * offset;
//    int boardsize=bd->getBoardSize();
//    if(r>=1 && r<=boardsize && l>=1 && l<=boardsize)
    return bd->getChessColor(Position(r,l));
//    return ChessColorPro::NOCHESS;
}
int ChesserAI::envaluateAt(Position p, ChessColorPro self,BoardModelInterface * bd)//对位置和棋的颜色进行估值
{
/*
    1 is self
    2 is opposite
    0 is nochess
    * is self position
*/
    int value = 0;
    ChessColorPro opposite = (self == ChessColorPro::BLACK) ? ChessColorPro::WHITE : ChessColorPro::BLACK; // 敌对方是谁

    for(int i=0; i<8; i++)  // 8个方向
    {
        //判断是否存在 *11110 ("活四" 必胜 没办法去赌了)
        if(getChessColor(p,i,1,bd) == self && getChessColor(p,i,2,bd) == self
                && getChessColor(p,i,3,bd) == self && getChessColor(p,i,4,bd) == self
                && getChessColor(p,i,5,bd) == NOCHESS)
        {
            value+=1000000;  // 100w
        }

        // 判断是否存在 21111* （死四A）  如果是己方则下子获得胜利，对手的话要竭力去赌
        if(getChessColor(p,i,1,bd) == self &&getChessColor(p,i,2,bd) == self
                && getChessColor(p,i,3,bd) == self &&getChessColor(p,i,4,bd) == self
                &&( getChessColor(p,i,5,bd) == opposite|| getChessColor(p, i, 5,bd) ==OUTRANGE))
        {
            value += 100000; // 10w
        }

        // 判断是否存在 111*1 （死四B）
        if(getChessColor(p,i,-1,bd) == self &&getChessColor(p,i,1,bd) == self
                && getChessColor(p,i,2,bd) == self &&getChessColor(p,i,3,bd) == self)
        {
            value += 100000; // 10w

        }
        //判断是否存在11*11 死四C
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 2,bd) == self && getChessColor(p, i, -1,bd) == self && getChessColor(p, i, -2,bd) == self)
        {
            value += 50000;// 5w
        }
        //判断是否存在活三 *1110
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 2,bd) == self && getChessColor(p, i, 3,bd) == self && getChessColor(p, i, 4,bd) == NOCHESS)
        {
            value += 50000;// 5w
        }

        //  01*110  活三
        if (getChessColor(p, i, -1,bd) == self && getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 2,bd) == self && getChessColor(p, i, 3,bd) == NOCHESS && getChessColor(p, i, -2,bd)==NOCHESS)
        {
            value += 50000;//5w
        }
        //0*1112  死三
        if (getChessColor(p, i, -1,bd) == NOCHESS && getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 2,bd) == self && getChessColor(p, i, 3,bd) == self && (getChessColor(p, i, 4,bd)==opposite|| getChessColor(p, i, 4,bd)==OUTRANGE))
        {
            value += 10000;//1w
        }
        //*01112
        if (getChessColor(p, i, 4,bd) == self && getChessColor(p, i, 3,bd) == self && getChessColor(p, i, 2,bd) == self && getChessColor(p, i, 1,bd) == NOCHESS &&( getChessColor(p, i, 4,bd)==opposite|| getChessColor(p, i, 4,bd) == OUTRANGE))
        {
            value += 10000;//1w
        }
        //01*112
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 2,bd) == self && getChessColor(p, i, -1,bd) == self && getChessColor(p, i, -2,bd) == NOCHESS &&( getChessColor(p, i, 3,bd) == opposite|| getChessColor(p, i, 3,bd) == OUTRANGE))
        {
            value += 10000;//1w
        }
        //*10112
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 3,bd) == self && getChessColor(p, i,4,bd) == self && getChessColor(p, i, 2,bd) == NOCHESS && (getChessColor(p, i, 4,bd) == opposite|| getChessColor(p, i, 4,bd) == OUTRANGE))
        {
            value += 10000;//1w
        }
        //*11012
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 2,bd) == self && getChessColor(p, i, 4,bd) == self && getChessColor(p, i, 3,bd) == NOCHESS && (getChessColor(p, i, 4,bd) == opposite|| getChessColor(p, i, 4,bd) == OUTRANGE))
        {
            value += 10000;//1w
        }
        //011*12
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, -2,bd) == self && getChessColor(p, i, -1,bd) == self && getChessColor(p, i, -3,bd) == NOCHESS && (getChessColor(p, i, 2,bd) == opposite|| getChessColor(p, i, 2,bd) == OUTRANGE))
        {
            value += 10000;//1w
        }
        //10*11
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, -2,bd) == self && getChessColor(p, i, 2,bd) == self && getChessColor(p, i, -1,bd) == NOCHESS )
        {

            value += 1000;//1k
        }
        //1*011
        if (getChessColor(p, i, 2,bd) == self && getChessColor(p, i, 3,bd) == self && getChessColor(p, i, -1,bd) == self && getChessColor(p, i, 1,bd) == NOCHESS)
        {
            value += 1000;//1k
        }
        //1*101
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 3,bd) == self && getChessColor(p, i, -1,bd) == self && getChessColor(p, i, 2,bd) == NOCHESS )
        {
            value += 1000;//1k
        }
        //2*1110
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 2,bd) == self && getChessColor(p, i, 3,bd) == self && getChessColor(p, i, 4,bd) == NOCHESS && (getChessColor(p, i, -1,bd) == opposite||getChessColor(p, i, -1,bd)==OUTRANGE))
        {
            value += 1000;//1k
        }
        //20111*
        if (getChessColor(p, i, -1,bd) == self && getChessColor(p, i, -2,bd) == self && getChessColor(p, i, -3,bd) == self && getChessColor(p, i, -4,bd) == NOCHESS && (getChessColor(p, i, -5,bd) == opposite|| getChessColor(p, i, -5,bd) == OUTRANGE))
        {
            value+= 1000;
        }
        ////活二 0*110
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 2,bd) == self && getChessColor(p, i, 3,bd) == NOCHESS && getChessColor(p, i, -1,bd) == NOCHESS)
        {
            value += 100;
        }
        // *0110
        if (getChessColor(p, i, 2,bd) == self && getChessColor(p, i, 3,bd) == self && getChessColor(p, i, 1,bd) == NOCHESS && getChessColor(p, i, 4,bd) == NOCHESS)
        {
            value += 100;
        }
        //0011*
        if (getChessColor(p, i, -1,bd) == self && getChessColor(p, i, -2,bd) == self && getChessColor(p, i,-3,bd) == NOCHESS && getChessColor(p, i, -4,bd) == NOCHESS)
        {
            value += 100;
        }
        //01*10
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, -1,bd) == self && getChessColor(p, i, 2,bd) == NOCHESS && getChessColor(p, i, -2,bd) == NOCHESS)
        {
            value += 100;
        }
        //*1010
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 3,bd) == self && getChessColor(p, i, 2,bd) == NOCHESS && getChessColor(p, i, 4,bd) == NOCHESS)
        {
            value += 100;
        }
        //*1001
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 4,bd) == self && getChessColor(p, i, 2,bd) == NOCHESS && getChessColor(p, i, 3,bd) == NOCHESS)
        {
            value += 100;
        }
        //01*01
        if (getChessColor(p, i, 2,bd) == self && getChessColor(p, i, -1,bd) == self && getChessColor(p, i, 1,bd) == NOCHESS && getChessColor(p, i, -2,bd) == NOCHESS)
        {
            value += 100;
        }
        //010*1
        if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, -2,bd) == self && getChessColor(p, i, -1,bd) == NOCHESS && getChessColor(p, i, -3,bd) == NOCHESS)
            {
                value += 100;
            }
        /////死二
        //*00112
            if (getChessColor(p, i, 3,bd) == self && getChessColor(p, i, 4,bd) == self && getChessColor(p, i, 1,bd) == NOCHESS && getChessColor(p, i, 2,bd) == NOCHESS&&(getChessColor(p,i,5,bd)==opposite|| getChessColor(p, i, 5,bd) == OUTRANGE))
            {
                value += 10;
            }
            //0*0112
            if (getChessColor(p, i, 2,bd) == self && getChessColor(p, i, 3,bd) == self && getChessColor(p, i, -1,bd) == NOCHESS && getChessColor(p, i, 1,bd) == NOCHESS &&( getChessColor(p, i, 4,bd) == opposite|| getChessColor(p, i, 4,bd) == OUTRANGE))
            {
                value += 10;
            }
            //00*112
            if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 2,bd) == self && getChessColor(p, i, -1,bd) == NOCHESS && getChessColor(p, i, -2,bd) == NOCHESS && (getChessColor(p, i, 3,bd) == opposite|| getChessColor(p, i, 3,bd) == OUTRANGE))
            {
                value += 10;
            }
            //*10012
            if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, 4,bd) == self && getChessColor(p, i, 2,bd) == NOCHESS && getChessColor(p, i, 3,bd) == NOCHESS && (getChessColor(p, i, 5,bd) == opposite|| getChessColor(p, i, 5,bd)==OUTRANGE))
            {
                value += 10;
            }
            //01*012
            if (getChessColor(p, i, 2,bd) == self && getChessColor(p, i, -1,bd) == self && getChessColor(p, i,1,bd) == NOCHESS && getChessColor(p, i, -2,bd) == NOCHESS &&( getChessColor(p, i, 3,bd) == opposite|| getChessColor(p, i, 3,bd)==OUTRANGE))
            {
                value += 10;
            }
            //010*12
            if (getChessColor(p, i, 1,bd) == self && getChessColor(p, i, -2,bd) == self && getChessColor(p, i, -1,bd) == NOCHESS && getChessColor(p, i, -3,bd) == NOCHESS && (getChessColor(p, i, 2,bd) == opposite|| getChessColor(p, i, 2,bd)==OUTRANGE))
            {
                value += 10;
            }
        if (getChessColor(p, i, -1,bd) == self && getChessColor(p, i, 1,bd) == NOCHESS
                && getChessColor(p,i,2,bd) == NOCHESS && getChessColor(p,i,3,bd) == NOCHESS)
        {
            value +=10;
        }
        //10*01
        if (getChessColor(p, i, 2,bd) == self && getChessColor(p, i,-2,bd) == self
            && getChessColor(p, i, 1,bd) == NOCHESS && getChessColor(p, i, -1,bd) == NOCHESS)
        {
            value +=10;
        }

        // 周围如果已有棋子数目比较多的话，适当增加一下权值
        value += (getChessColor(p,i,-1,bd)== self
                  +getChessColor(p,i,-1,bd)==opposite)*1;
    }
    return value;
}
