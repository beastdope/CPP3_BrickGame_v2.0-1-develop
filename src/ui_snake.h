/********************************************************************************
** Form generated from reading UI file 'snake.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKE_H
#define UI_SNAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Snake
{
public:
    QLabel *labelCounter;
    QLabel *labelTime;

    void setupUi(QWidget *Snake)
    {
        if (Snake->objectName().isEmpty())
            Snake->setObjectName(QString::fromUtf8("Snake"));
        Snake->resize(400, 420);
        labelCounter = new QLabel(Snake);
        labelCounter->setObjectName(QString::fromUtf8("labelCounter"));
        labelCounter->setGeometry(QRect(0, 398, 401, 20));
        labelCounter->setAlignment(Qt::AlignCenter);
        labelTime = new QLabel(Snake);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setGeometry(QRect(0, 150, 400, 90));
        QFont font;
        font.setPointSize(32);
        font.setBold(true);
        font.setWeight(75);
        labelTime->setFont(font);
        labelTime->setAlignment(Qt::AlignCenter);

        retranslateUi(Snake);

        QMetaObject::connectSlotsByName(Snake);
    } // setupUi

    void retranslateUi(QWidget *Snake)
    {
        Snake->setWindowTitle(QCoreApplication::translate("Snake", "Snake", nullptr));
        labelCounter->setText(QCoreApplication::translate("Snake", "0", nullptr));
        labelTime->setText(QCoreApplication::translate("Snake", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Snake: public Ui_Snake {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKE_H
