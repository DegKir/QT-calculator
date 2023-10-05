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
    void on_erase_button_clicked();
    void on_equality_button_clicked();



private:
    int memory=0;
    bool last_operator_plus = false;
    bool last_operator_mult = false;
    bool last_operator_minus = false;
    bool ready_to_print_new_number = true;
    Ui::Form *ui;
};

#endif // FORM_H
