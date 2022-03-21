/********************************************************************************
** Form generated from reading UI file 'weilcome.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEILCOME_H
#define UI_WEILCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_weilcome
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *weilcome)
    {
        if (weilcome->objectName().isEmpty())
            weilcome->setObjectName(QStringLiteral("weilcome"));
        weilcome->resize(400, 300);
        label = new QLabel(weilcome);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 20, 181, 111));
        pushButton = new QPushButton(weilcome);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 150, 75, 23));
        pushButton_2 = new QPushButton(weilcome);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 190, 75, 23));

        retranslateUi(weilcome);

        QMetaObject::connectSlotsByName(weilcome);
    } // setupUi

    void retranslateUi(QDialog *weilcome)
    {
        weilcome->setWindowTitle(QApplication::translate("weilcome", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("weilcome", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:600;\">2048</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("weilcome", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("weilcome", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class weilcome: public Ui_weilcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEILCOME_H
