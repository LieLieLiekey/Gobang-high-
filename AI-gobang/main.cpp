#include "mainwindow.h"

#include <QApplication>
#include "boardframe.h"
#include <QFrame>
#include "boardmodel.h"
#include "control.h"
#include "showinfoframe.h"
#include "showinfoframeui.h"
#include "selectmodeldialogui.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    ShowInfoFrameUi w(nullptr,nullptr,"dch","alphgo",100);
//    w.begin();
   Control dch;
   dch.begin();
//    SelectModelDialogUi w;
//    w.exec();
//    qDebug() << "user1:"<<w.getUser1Name()<<" user2:"<<w.getUser2Name()<<"\n";
//    switch (w.getModel()) {
//        case SelectModelDialogUi::AI_MODEl:
//         qDebug()<<" AI_Model"<<"\n";
//        break;
//        case SelectModelDialogUi::DOUBLE_MODEL:
//        qDebug()<<"double model"<<"\n";
//       break;
//    }
   int status= a.exec();
   qDebug() << " exec end.\n";
   return status;
}
