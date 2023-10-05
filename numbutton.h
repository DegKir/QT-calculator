#ifndef NUMBUTTON_H
#define NUMBUTTON_H

#include <QPushButton>
#include <QWidget>

class NumButton : public QPushButton
{
    Q_OBJECT
public:
    NumButton(QWidget* parent = nullptr);
};

#endif // NUMBUTTON_H
