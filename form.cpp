#include "form.h"
#include "ui_form.h"
//#include "QShortcut"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    //QShortcut *shortcut = new QShortcut(QKeySequence("1"), parent);
    //connect(ui->one_button, &QPushButton::clicked, this, &Form::on_one_button_clicked);
    //connect(ui->one_button, &QPushButton::clicked, this, &Form::on_one_button_clicked);
    //connect(ui->two_button, &QPushButton::clicked, this, &Form::on_two_button_clicked);
    //connect(ui->three_button, &QPushButton::clicked, this, &Form::on_three_button_clicked);
    //connect(ui->four_button, &QPushButton::clicked, this, &Form::on_four_button_clicked);
    //connect(ui->five_button, &QPushButton::clicked, this, &Form::on_five_button_clicked);
    //connect(ui->six_button, &QPushButton::clicked, this, &Form::on_six_button_clicked);
    //connect(ui->seven_button, &QPushButton::clicked, this, &Form::on_seven_button_clicked);
    //connect(ui->eigh_button, &QPushButton::clicked, this, &Form::on_eigh_button_clicked);
    //connect(ui->nine_button, &QPushButton::clicked, this, &Form::on_nine_button_clicked);
    //connect(ui->zero_button, &QPushButton::clicked, this, &Form::on_zero_button_clicked);
    //connect(ui->erase_button, &QPushButton::clicked, this, &Form::on_erase_button_clicked);
    //connect(ui->plus_button, &QPushButton::clicked, this, &Form::on_plus_button_clicked);
    for(auto& btn : findChildren<QPushButton*>())
    {
        connect(btn, &QPushButton::clicked, this, [this, btn]()
        {
            auto clearOnInput = false;
            static int savedArg = -1;
            auto op  = btn->text();
            auto str = ui->lineEdit->text();
            if(op == "0" && (str.isEmpty() || str.toDouble() == 0))
            {
                return;
            }
            else if (op == "+")
            {
                if(savedArg>=0)
                {
//                    int op1 = savedArg.toInt();
                    int op1 = savedArg;
                    int op2 = str.toInt();
                    str = QString::number(op1+op2);
                    ui->lineEdit->setText(str);
                    clearOnInput = true;
                    savedArg = -1;
                }
                else
                {
                    savedArg = str.toInt();
                    ui->lineEdit->clear();
                }
            }
            else if (op == "erase")
            {
                ui->lineEdit->clear();
                savedArg=-1;
            }
            else
            {
                if(clearOnInput)
                {
                    savedArg = str.toInt();
                    str.clear();
                    clearOnInput = false;
                }
                str.append(btn->text());
                ui->lineEdit->setText(str);
            }
        });
    }

}

Form::~Form()
{
    delete ui;
}

//void Form::on_one_button_clicked()
//{
//    auto str = ui->lineEdit->text();
//    str.append("1");
//    ui->lineEdit->setText(str);
//}

//void Form::on_two_button_clicked()
//{
//    auto str = ui->lineEdit->text();
//    str.append("2");
//    ui->lineEdit->setText(str);
//}

//void Form::on_three_button_clicked()
//{
//    auto str = ui->lineEdit->text();
//    str.append("3");
//    ui->lineEdit->setText(str);
//}

//void Form::on_four_button_clicked()
//{
//    auto str = ui->lineEdit->text();
//    str.append("4");
//    ui->lineEdit->setText(str);
//}

//void Form::on_five_button_clicked()
//{
//    auto str = ui->lineEdit->text();
//    str.append("5");
//    ui->lineEdit->setText(str);
//}

//void Form::on_six_button_clicked()
//{
//    auto str = ui->lineEdit->text();
//    str.append("6");
//    ui->lineEdit->setText(str);
//}


//void Form::on_seven_button_clicked()
//{
//    auto str = ui->lineEdit->text();
//    str.append("7");
//    ui->lineEdit->setText(str);
//}

//void Form::on_eigh_button_clicked()
//{
//    auto str = ui->lineEdit->text();
//    str.append("8");
//    ui->lineEdit->setText(str);
//}

//void Form::on_nine_button_clicked()
//{
//    auto str = ui->lineEdit->text();
//    str.append("9");
//    ui->lineEdit->setText(str);
//}


//void Form::on_zero_button_clicked()
//{
//    auto str = ui->lineEdit->text();
//    if(str.isEmpty() || str.toDouble() == 0)
//        return;
//    str.append("0");
//    ui->lineEdit->setText(str);
//}


//void Form::on_erase_button_clicked()
//{
//    ui->lineEdit->setText("");
//}


//void Form::on_plus_button_clicked()
//{
//    auto str = ui->lineEdit->text();
//    str.append("+");
//    ui->lineEdit->setText(str);
//}

