/********************************************************************************
** Form generated from reading UI file 'playSound2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYSOUND2_H
#define UI_PLAYSOUND2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playSound2Class
{
public:
    QPushButton *btn_start;
    QPushButton *btn_stop;

    void setupUi(QWidget *playSound2Class)
    {
        if (playSound2Class->objectName().isEmpty())
            playSound2Class->setObjectName(QString::fromUtf8("playSound2Class"));
        playSound2Class->resize(600, 400);
        btn_start = new QPushButton(playSound2Class);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(15, 136, 151, 61));
        btn_stop = new QPushButton(playSound2Class);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setGeometry(QRect(185, 136, 141, 61));

        retranslateUi(playSound2Class);

        QMetaObject::connectSlotsByName(playSound2Class);
    } // setupUi

    void retranslateUi(QWidget *playSound2Class)
    {
        playSound2Class->setWindowTitle(QApplication::translate("playSound2Class", "playSound2", nullptr));
        btn_start->setText(QApplication::translate("playSound2Class", "\345\274\200\345\247\213\345\275\225\351\237\263", nullptr));
        btn_stop->setText(QApplication::translate("playSound2Class", "\345\201\234\346\255\242\345\275\225\351\237\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class playSound2Class: public Ui_playSound2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYSOUND2_H
