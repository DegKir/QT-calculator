#include "form.h"
#include "ui_form.h"
//#include "QShortcut"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


    for(auto& btn : findChildren<NumButton*>())
    {
        connect(btn, &QPushButton::clicked, this, [this, btn]()
        {
            if(ready_to_print_new_number)
            {
                ui->lineEdit->clear();
                ready_to_print_new_number = false;
            }
            auto str = ui->lineEdit->text();
            if(btn->text() == "0")
            {
                if(str.isEmpty() || str.toDouble() == 0)
                    return;
            }
            str.append(btn->text());
            ui->lineEdit->setText(str);
        });
    }

    for(auto& btn : findChildren<OperButton*>())
    {
        connect(btn, &QPushButton::clicked, this, [this, btn]()
        {
            auto str = ui->lineEdit->text();
            int last_operand = str.toInt();
            if(last_operator_plus)
            {
                memory += last_operand;
                last_operator_plus = false;
            }
            else if(last_operator_mult)
            {
                memory *= last_operand;
                last_operator_mult = false;
            }
            else if(last_operator_minus)
            {
                memory -= last_operand;
                last_operator_minus = false;
            }
            else
            {
                memory = str.toInt();
            }



            if(btn->text() == "+")
            {
                last_operator_plus = true;
                last_operator_minus = false;
                last_operator_mult = false;
            }
            if(btn->text() == "-")
            {
                last_operator_plus = false;
                last_operator_minus = true;
                last_operator_mult = false;
            }
            if(btn->text() == "x")
            {
                last_operator_plus = false;
                last_operator_minus = false;
                last_operator_mult = true;
            }
            ui->lineEdit->clear();
            ui->lineEdit->setText(QString::number(memory));
            ready_to_print_new_number = true;
        });
    }
}

Form::~Form()
{
    delete ui;
}


void Form::on_equality_button_clicked()
{
    auto str = ui->lineEdit->text();
    int last_operand = str.toInt();
    if(last_operator_plus)
    {
        memory += last_operand;
        last_operator_plus = false;
    }
    if(last_operator_mult)
    {
        memory *= last_operand;
        last_operator_mult = false;
    }
    if(last_operator_minus)
    {
        memory -= last_operand;
        last_operator_minus = false;
    }
    ui->lineEdit->setText(QString::number(memory));
    ready_to_print_new_number = true;
    memory = 0;
}

void Form::on_erase_button_clicked()
{
    int memory=0;
    bool last_operator_plus = false;
    bool last_operator_mult = false;
    bool last_operator_minus = false;
    bool ready_to_print_new_number = true;
    ui->lineEdit->setText("");
}

