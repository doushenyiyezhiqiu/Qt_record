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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playSound2Class
{
public:

    void setupUi(QWidget *playSound2Class)
    {
        if (playSound2Class->objectName().isEmpty())
            playSound2Class->setObjectName(QString::fromUtf8("playSound2Class"));
        playSound2Class->resize(600, 400);

        retranslateUi(playSound2Class);

        QMetaObject::connectSlotsByName(playSound2Class);
    } // setupUi

    void retranslateUi(QWidget *playSound2Class)
    {
        playSound2Class->setWindowTitle(QApplication::translate("playSound2Class", "playSound2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class playSound2Class: public Ui_playSound2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYSOUND2_H
