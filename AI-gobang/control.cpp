#include "control.h"
#include <QMessageBox>
/*
class Control:public ControlInterface
{
public:
    Control();
    ~Control();
    void putChessSignal(Position pos) override;
    void giveUpSignal(ChessColorPro ) override;
    void exitSignal(ChessColorPro) override;
    void timeOutSingal(ChessColorPro) override;
    void begin();
    void gameOverHandle();
private :
    BoardModel * boardmodel;
    Chesser *whiteer,*blacker;
    BoardFrame * boardframe;
    ShowInfoFrameUi *showinfo_ui;
    QFrame *frame;
};

*/
#include "selectmodeldialogui.h"
Control::Control(int timeout)
{
    SelectModelDialogUi * selectmodel=new SelectModelDialogUi;
    selectmodel->exec();
    switch (selectmodel->getModel())
    {
        case SelectModelDialogUi::AI_MODEl:
            game_model = AI_MODEL;
            break;
        case SelectModelDialogUi::DOUBLE_MODEL:
            game_model = DOUBLE_MODEL;
            break;
        default:
            game_model = DOG_MODEL;
    }
    if(game_model == AI_MODEL){
        setAIModel(selectmodel->getUser1Name());
    }
    else if(game_model == DOUBLE_MODEL){
        setDoubleModel(selectmodel->getUser1Name(),selectmodel->getUser2Name());
    }
    else{
//        qDebug()<<"except eixt";
        exit(0);
    }
//    qDebug()<<"sign1 end.\n";
    delete selectmodel;
    /*设置棋手完毕*/
    boardmodel = new BoardModel(blacker,whiteer);
    boardframe = new BoardFrame(boardmodel,this,550,boardmodel->getBoardSize());
    showinfo_ui = new ShowInfoFrameUi(this,boardmodel,QString(blacker->getName().c_str()),QString(whiteer->getName().c_str()),timeout);
    /*初始化model和view完毕*/
    boardmodel->addObserver(boardframe);
    boardmodel->addObserver(showinfo_ui);
    /*将观察者 注册 到 主题完毕*/
    frame = new QFrame();
    frame->setFixedSize(850,550);
    boardframe->setParent(frame);
    showinfo_ui->setParent(frame);
    boardframe->move(0,0);
    showinfo_ui->move(550,0);
    /*UI窗口的组合完毕*/

    end_flag = Control::NOEND;
    /*初始化完毕*/
}
void Control::setAIModel(QString black_name)
{
    blacker = new ChesserMan(black_name.toUtf8().data(),ChessColorPro::BLACK);
    whiteer = new ChesserAI("Alphgo",ChessColorPro::WHITE);
}
void Control::setDoubleModel(QString black_name,QString white_name)
{
    blacker = new ChesserMan(black_name.toUtf8().data(),ChessColorPro::BLACK);
    whiteer = new ChesserMan(white_name.toUtf8().data(),ChessColorPro::WHITE);

}
void Control::putChessSignal(Position pos)
{
    static Position tmppos;
    ChessColorPro now=boardmodel->getNowColor();
    boardmodel->putChess(pos,now);
    while(!boardmodel->is_gameOver()){
           Chesser * ch = boardmodel -> getNowChesser();
           if(ch->putChess(boardmodel,tmppos)){
               boardmodel->putChess(tmppos,ch->getColor());
           }
           else{
               return ;//让GUI去触发
           }
    }
    end_flag=END_FLAGS::END;
    gameOverHandle();
}
void Control::giveUpSignal(ChessColorPro)
{
    QMessageBox msgBox;
    msgBox.setText("Warning ");
    msgBox.setInformativeText("Do you want to give up ?");
    msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    switch (ret) {
      case QMessageBox::No:
          // Save was clicked
          break;
      case QMessageBox::Yes:
        end_flag=END_FLAGS::GAVEUP;
        gameOverHandle();
          break;
      default:
          // should never be reached
          break;
    }
//    qDebug()<<"giveUpSignal"<<" !!!\n";
}
void Control::exitSignal(ChessColorPro)
{
    QMessageBox msgBox;
    msgBox.setText("Warning ");
    msgBox.setInformativeText("Do you want to exit ?");
    msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    switch (ret) {
      case QMessageBox::No:
         //No
          break;
      case QMessageBox::Yes:
        //yes
        exitHandle();
          break;
      default:
          break;
    }
//     qDebug()<<"exitSignal"<<" !!!\n";
}
void Control::timeOutSingal(ChessColorPro)
{
    QMessageBox msgBox;
    msgBox.setText("Warning ");
    msgBox.setInformativeText("You're too slow.");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.exec();
    end_flag=END_FLAGS::TIMEOUT;
    gameOverHandle();
}
void Control::exitHandle()
{
    frame->close();
}
void Control::gameOverHandle()
{
    /*
     Coudle be  :give up ,win,dogfall,timeout
    */
    QString infoname;
    if(end_flag==END_FLAGS::END)
    {
        if(boardmodel->is_DogFall()){
               infoname = "Dogfall.";
        }
        else if(boardmodel->whoWin() == ChessColorPro::BLACK){
             infoname = QString(blacker->getName().c_str()) + "  ( BLACK ) is  Winer!";
        }
        else{
            infoname = QString(whiteer->getName().c_str()) + "  ( WHITE ) is  Winer!";
        }
    }
    else if(end_flag==END_FLAGS::GAVEUP)
    {
        Chesser *chesser = boardmodel ->getNowChesser();
        infoname = QString(chesser->getName().c_str()) + " is Loser!";
    }
    else if(end_flag==END_FLAGS::TIMEOUT)
    {
        //另一方胜利
        if(boardmodel->getNowColor() == ChessColorPro::WHITE){
             infoname = QString(blacker->getName().c_str()) + "  ( BLACK ) is  Winer!";
        }
        else{
            infoname = QString(whiteer->getName().c_str()) + "  ( WHITE ) is  Winer!";
        }
    }
    else{
        infoname = "error.\n";
    }
    QMessageBox msgBox;
    msgBox.setText("Game over");
    msgBox.setInformativeText(infoname);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.exec();

    frame->close();
}
void Control::begin()
{
    frame->show();
}
Control::~Control()
{
    //delete boardframe;
    delete frame;
    delete boardmodel;
    delete whiteer;
    delete blacker;
}
