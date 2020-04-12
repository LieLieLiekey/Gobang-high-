#include "selectmodeldialogui.h"
#include "ui_selectmodeldialogui.h"

SelectModelDialogUi::SelectModelDialogUi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectModelDialogUi)
{
    ui->setupUi(this);
    ai_radio=ui->ai_radio;
    double_radio=ui->double_radio;
    user1_line=ui->user1_line;
    user2_line=ui->user2_line;
    enter_bt=ui->enter_button;

    connect(ai_radio,&QRadioButton::clicked,[&](){
        model=AI_MODEl;
        setAiModel();
    });//checked

    connect(double_radio,&QRadioButton::clicked,[&](){
        model=DOUBLE_MODEL;
        setDoubleModel();
    });
    ai_radio->setChecked(true);
    model=AI_MODEl;
    setAiModel();
    connect(enter_bt,&QPushButton::clicked,[=]{
        user1_name=user1_line->text();
        user2_name=user2_line->text();
        close();
    });
}
typename SelectModelDialogUi::GAME_MODEL SelectModelDialogUi::getModel()
{
    return model;
}
QString SelectModelDialogUi::getUser1Name()
{
    return user1_name;
}
QString SelectModelDialogUi::getUser2Name()
{
    return user2_name;
}
void SelectModelDialogUi::setAiModel()
{
        user2_line->setDisabled(true);
}
void SelectModelDialogUi::setDoubleModel()
{
        user2_line->setEnabled(true);
}
SelectModelDialogUi::~SelectModelDialogUi()
{
    delete ui;
}
