#ifndef MAINWINDOWGAMEWON_H
#define MAINWINDOWGAMEWON_H

#include <QMainWindow>

namespace Ui {
class MainWindowGameWon;
}

class MainWindowGameWon : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowGameWon(QWidget *parent = nullptr);
    ~MainWindowGameWon();

private:
    Ui::MainWindowGameWon *ui;
};

#endif // MAINWINDOWGAMEWON_H
