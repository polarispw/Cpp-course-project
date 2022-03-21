#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QDialog>

namespace Ui {
class instruction;
}

class instruction : public QDialog
{
    Q_OBJECT

public:
    explicit instruction(QWidget *parent = nullptr);
    ~instruction();
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();

private:
    Ui::instruction *ui;
#define WINWIDTH 500//窗口宽度
#define WINHEIGHT 600//窗口高度
};

#endif // INSTRUCTION_H
