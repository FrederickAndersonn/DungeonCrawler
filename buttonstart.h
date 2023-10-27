#ifndef BUTTONSTART_H
#define BUTTONSTART_H

#include <QPushButton>

class ButtonStart: public QPushButton
{
    Q_OBJECT
public slots:
    void thisSlot();
public:
    ButtonStart(QWidget* parent);

signals:

private:
    bool endet;
};
#endif // BUTTONSTART_H
