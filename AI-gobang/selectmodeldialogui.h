#ifndef SELECTMODELDIALOGUI_H
#define SELECTMODELDIALOGUI_H

#include <QDialog>
#include <QString>
#include <QRadioButton>
#include <QLineEdit>
#include <QPushButton>
namespace Ui {
class SelectModelDialogUi;
}

class SelectModelDialogUi : public QDialog
{
    Q_OBJECT

public:
    using GAME_MODEL=enum{AI_MODEl,DOUBLE_MODEL,AA_MODEL};
    explicit SelectModelDialogUi(QWidget *parent = nullptr);
    GAME_MODEL getModel();
    QString getUser1Name();
    QString getUser2Name();
    void setAiModel();
    void setDoubleModel();
    ~SelectModelDialogUi();
private:
    Ui::SelectModelDialogUi *ui;
    GAME_MODEL model;
    QPushButton *enter_bt;
    QLineEdit *user1_line,*user2_line;
    QRadioButton *ai_radio,*double_radio;
    QString user1_name,user2_name;

};

#endif // SELECTMODELDIALOGUI_H
