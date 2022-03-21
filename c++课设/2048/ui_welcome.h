/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_welcome
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *welcome)
    {
        if (welcome->objectName().isEmpty())
            welcome->setObjectName(QStringLiteral("welcome"));
        welcome->resize(400, 300);
        pushButton = new QPushButton(welcome);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 170, 86, 27));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(welcome);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 220, 86, 27));
        pushButton_2->setFont(font);
        pushButton_2->setFlat(true);

        retranslateUi(welcome);

        QMetaObject::connectSlotsByName(welcome);
    } // setupUi

    void retranslateUi(QDialog *welcome)
    {
        welcome->setWindowTitle(QApplication::translate("welcome", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("welcome", "\345\274\200\345\247\213\346\270\270\346\210\217", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("welcome", "\346\270\270\346\210\217\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class welcome: public Ui_welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
