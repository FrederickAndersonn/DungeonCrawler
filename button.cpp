#include "button.h"



Button::Button(QWidget *parent, int number): QPushButton(parent), value(number)
{
    connect(parent, SIGNAL(clicked()), this, SLOT(thisSlot()));
}

void Button::thisSlot()
{
    emit valueButton(value);
}

