#ifndef OPERBUTTON_H
#define OPERBUTTON_H

#include <QPushButton>
#include <QWidget>

class OperButton : public QPushButton
{
    Q_OBJECT
public:
    OperButton(QWidget* parent = nullptr);
};

#endif // OPERBUTTON_H
