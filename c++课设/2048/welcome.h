#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>

namespace Ui {
class welcome;
}

class welcome : public QDialog
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = nullptr);
    ~welcome();
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::welcome *ui;
#define WINWIDTH 500//窗口宽度
#define WINHEIGHT 600//窗口高度
};

#endif // WELCOME_H
