#ifndef BUTTON_H
#define BUTTON_H


#include <QPushButton>

class Button: public QPushButton
{
    Q_OBJECT
public slots:
    void thisSlot();
public:
    Button(QWidget* parent, int);

signals:
    void valueButton(int value);

private:
    int value;
};
#endif // BUTTON_H
