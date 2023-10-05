#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
//    void on_one_button_clicked();

//    void on_two_button_clicked();

//    void on_eigh_button_clicked();

//    void on_five_button_clicked();

//    void on_three_button_clicked();

//    void on_four_button_clicked();

//    void on_six_button_clicked();

//    void on_seven_button_clicked();

//    void on_nine_button_clicked();

//    void on_zero_button_clicked();

//    void on_erase_button_clicked();

//    void on_plus_button_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
