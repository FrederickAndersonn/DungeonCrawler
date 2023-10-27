#ifndef MAINWINDOWGAMELOST_H
#define MAINWINDOWGAMELOST_H

#include <QMainWindow>

namespace Ui {
class MainWindowGameLost;
}

class MainWindowGameLost : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowGameLost(QWidget *parent = nullptr);
    ~MainWindowGameLost();

private:
    Ui::MainWindowGameLost *ui;
};

#endif // MAINWINDOWGAMELOST_H
