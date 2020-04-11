/********************************************************************************
** Form generated from reading UI file 'showinfoframeui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWINFOFRAMEUI_H
#define UI_SHOWINFOFRAMEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowInfoFrameUi
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *top_layout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *color_label;
    QLabel *black_title;
    QLabel *white_title;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *name_label;
    QLabel *black_name;
    QLabel *white_name;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *residue_label;
    QLabel *black_redisdue;
    QLabel *white_residue;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *giveup_button;
    QToolButton *exit_button;
    QVBoxLayout *bottom_layout;
    QLabel *label_2;

    void setupUi(QWidget *ShowInfoFrameUi)
    {
        if (ShowInfoFrameUi->objectName().isEmpty())
            ShowInfoFrameUi->setObjectName(QStringLiteral("ShowInfoFrameUi"));
        ShowInfoFrameUi->resize(300, 550);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(153, 205, 239, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(204, 230, 247, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(76, 102, 119, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(102, 137, 159, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        ShowInfoFrameUi->setPalette(palette);
        ShowInfoFrameUi->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(ShowInfoFrameUi);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        top_layout = new QVBoxLayout();
        top_layout->setSpacing(0);
        top_layout->setObjectName(QStringLiteral("top_layout"));
        top_layout->setSizeConstraint(QLayout::SetFixedSize);
        frame_3 = new QFrame(ShowInfoFrameUi);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush8(QColor(0, 255, 127, 100));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush8);
        QBrush brush9(QColor(127, 255, 191, 100));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush9);
        QBrush brush10(QColor(63, 255, 159, 100));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        QBrush brush11(QColor(0, 127, 63, 100));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush11);
        QBrush brush12(QColor(0, 170, 84, 100));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush13(QColor(127, 255, 191, 177));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        frame_3->setPalette(palette1);
        frame_3->setAutoFillBackground(true);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        color_label = new QLabel(frame_3);
        color_label->setObjectName(QStringLiteral("color_label"));

        horizontalLayout_2->addWidget(color_label);

        black_title = new QLabel(frame_3);
        black_title->setObjectName(QStringLiteral("black_title"));

        horizontalLayout_2->addWidget(black_title);

        white_title = new QLabel(frame_3);
        white_title->setObjectName(QStringLiteral("white_title"));

        horizontalLayout_2->addWidget(white_title);


        top_layout->addWidget(frame_3);

        frame_2 = new QFrame(ShowInfoFrameUi);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush14(QColor(255, 255, 255, 100));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush14);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush14);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush14);
        QBrush brush15(QColor(127, 127, 127, 100));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush15);
        QBrush brush16(QColor(170, 170, 170, 100));
        brush16.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush16);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush14);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush17(QColor(255, 255, 255, 177));
        brush17.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        frame_2->setPalette(palette2);
        frame_2->setAutoFillBackground(true);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, 0);
        name_label = new QLabel(frame_2);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setAutoFillBackground(false);
        name_label->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(name_label);

        black_name = new QLabel(frame_2);
        black_name->setObjectName(QStringLiteral("black_name"));
        black_name->setAutoFillBackground(false);

        horizontalLayout_4->addWidget(black_name);

        white_name = new QLabel(frame_2);
        white_name->setObjectName(QStringLiteral("white_name"));
        white_name->setAutoFillBackground(false);
        white_name->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	rgb(255, 255, 255);\n"
"	font: 9pt \"Arvo\";\n"
"}\n"
""));

        horizontalLayout_4->addWidget(white_name);


        top_layout->addWidget(frame_2);

        frame = new QFrame(ShowInfoFrameUi);
        frame->setObjectName(QStringLiteral("frame"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush18(QColor(255, 170, 255, 100));
        brush18.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush18);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush14);
        QBrush brush19(QColor(255, 212, 255, 100));
        brush19.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush19);
        QBrush brush20(QColor(127, 85, 127, 100));
        brush20.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush20);
        QBrush brush21(QColor(170, 113, 170, 100));
        brush21.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush21);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush18);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush22(QColor(255, 212, 255, 177));
        brush22.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush22);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush18);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush19);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush20);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush21);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush18);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush22);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush18);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush19);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush21);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush18);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush18);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush18);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        frame->setPalette(palette3);
        frame->setAutoFillBackground(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        residue_label = new QLabel(frame);
        residue_label->setObjectName(QStringLiteral("residue_label"));

        horizontalLayout->addWidget(residue_label);

        black_redisdue = new QLabel(frame);
        black_redisdue->setObjectName(QStringLiteral("black_redisdue"));

        horizontalLayout->addWidget(black_redisdue);

        white_residue = new QLabel(frame);
        white_residue->setObjectName(QStringLiteral("white_residue"));

        horizontalLayout->addWidget(white_residue);


        top_layout->addWidget(frame);


        verticalLayout->addLayout(top_layout);

        frame_4 = new QFrame(ShowInfoFrameUi);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        giveup_button = new QToolButton(frame_4);
        giveup_button->setObjectName(QStringLiteral("giveup_button"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/png/image/surrender.png"), QSize(), QIcon::Normal, QIcon::Off);
        giveup_button->setIcon(icon);
        giveup_button->setIconSize(QSize(50, 50));
        giveup_button->setAutoRaise(true);

        horizontalLayout_3->addWidget(giveup_button);

        exit_button = new QToolButton(frame_4);
        exit_button->setObjectName(QStringLiteral("exit_button"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/png/image/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exit_button->setIcon(icon1);
        exit_button->setIconSize(QSize(50, 50));
        exit_button->setAutoRaise(true);

        horizontalLayout_3->addWidget(exit_button);


        verticalLayout->addWidget(frame_4);

        bottom_layout = new QVBoxLayout();
        bottom_layout->setObjectName(QStringLiteral("bottom_layout"));
        bottom_layout->setSizeConstraint(QLayout::SetFixedSize);
        label_2 = new QLabel(ShowInfoFrameUi);
        label_2->setObjectName(QStringLiteral("label_2"));

        bottom_layout->addWidget(label_2);


        verticalLayout->addLayout(bottom_layout);


        retranslateUi(ShowInfoFrameUi);

        QMetaObject::connectSlotsByName(ShowInfoFrameUi);
    } // setupUi

    void retranslateUi(QWidget *ShowInfoFrameUi)
    {
        ShowInfoFrameUi->setWindowTitle(QApplication::translate("ShowInfoFrameUi", "Form", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        ShowInfoFrameUi->setWhatsThis(QApplication::translate("ShowInfoFrameUi", "<html><head/><body><p>121</p><p><br/></p><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        color_label->setText(QApplication::translate("ShowInfoFrameUi", "Color:", Q_NULLPTR));
        black_title->setText(QApplication::translate("ShowInfoFrameUi", "Black", Q_NULLPTR));
        white_title->setText(QApplication::translate("ShowInfoFrameUi", "White", Q_NULLPTR));
        name_label->setText(QApplication::translate("ShowInfoFrameUi", "Name:", Q_NULLPTR));
        black_name->setText(QApplication::translate("ShowInfoFrameUi", "BlackName", Q_NULLPTR));
        white_name->setText(QApplication::translate("ShowInfoFrameUi", "WhiteName", Q_NULLPTR));
        residue_label->setText(QApplication::translate("ShowInfoFrameUi", "Residue time:", Q_NULLPTR));
        black_redisdue->setText(QApplication::translate("ShowInfoFrameUi", "BlackTime", Q_NULLPTR));
        white_residue->setText(QApplication::translate("ShowInfoFrameUi", "WhiteTime", Q_NULLPTR));
        giveup_button->setText(QApplication::translate("ShowInfoFrameUi", "...", Q_NULLPTR));
        exit_button->setText(QApplication::translate("ShowInfoFrameUi", "exit", Q_NULLPTR));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ShowInfoFrameUi: public Ui_ShowInfoFrameUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWINFOFRAMEUI_H
