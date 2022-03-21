/********************************************************************************
** Form generated from reading UI file 'instruction.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTION_H
#define UI_INSTRUCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_instruction
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *instruction)
    {
        if (instruction->objectName().isEmpty())
            instruction->setObjectName(QStringLiteral("instruction"));
        instruction->resize(400, 300);
        pushButton = new QPushButton(instruction);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(160, 242, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setFlat(true);
        label = new QLabel(instruction);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 110, 381, 121));

        retranslateUi(instruction);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(instruction);
    } // setupUi

    void retranslateUi(QDialog *instruction)
    {
        instruction->setWindowTitle(QApplication::translate("instruction", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("instruction", "\350\277\224\345\233\236\344\270\273\351\241\265\351\235\242", Q_NULLPTR));
        label->setText(QApplication::translate("instruction", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\346\214\211\342\200\234\342\206\221\342\200\235\343\200\201\342\200\234\342\206\223\342\200\235\343\200\201\342\200\234\342\206\220\342\200\235\343\200\201\342\200\234\342\206\222\342\200\235\346\223\215\344\275\234\346\226\271\345\235\227\347\247\273\345\212\250</span></p><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\345\220\214\346\225\260\345\200\274\346\226\271\345\235\227\347\233\270\351\201\207\345\220\216\344\274\232\347\273\223\345\220\210</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class instruction: public Ui_instruction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTION_H
