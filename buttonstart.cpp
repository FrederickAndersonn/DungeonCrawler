#include "buttonstart.h"

ButtonStart::ButtonStart(QWidget *parent): QPushButton(parent)
{
    connect(parent, SIGNAL(clicked()), this, SLOT(thisSlot()));
}

void ButtonStart::thisSlot()
{

}
