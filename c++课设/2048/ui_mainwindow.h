/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action1;
    QAction *action2;
    QAction *action1_2;
    QAction *action2_2;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(511, 429);
        action1 = new QAction(MainWindow);
        action1->setObjectName(QStringLiteral("action1"));
        action2 = new QAction(MainWindow);
        action2->setObjectName(QStringLiteral("action2"));
        action1_2 = new QAction(MainWindow);
        action1_2->setObjectName(QStringLiteral("action1_2"));
        action2_2 = new QAction(MainWindow);
        action2_2->setObjectName(QStringLiteral("action2_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 220, 141, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 230, 141, 81));
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 230, 141, 81));
        label_3->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 511, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action1);
        menu->addSeparator();
        menu->addAction(action2);
        menu_2->addAction(action1_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action1->setText(QApplication::translate("MainWindow", "\346\226\260\346\270\270\346\210\217", Q_NULLPTR));
        action2->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        action1_2->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        action2_2->setText(QApplication::translate("MainWindow", "\345\274\200\345\217\221\350\200\205\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "0\347\247\222", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "0\347\247\222", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "0\347\247\222", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\270\270\346\210\217", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
