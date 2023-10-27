#ifndef MAINWINDOWGAME_H
#define MAINWINDOWGAME_H

#include <QMainWindow>
#include <QLabel>
#include "GraphicalUI.h"
#include "button.h"
#include <iostream>

class DungeonCrawler;

namespace Ui {
class MainWindowGame;
}

class MainWindowGame : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowGame(GraphicalUI* gui,QWidget *parent = nullptr);

    MainWindowGame(GraphicalUI* gui, DungeonCrawler*, QWidget *parent = nullptr);

    ~MainWindowGame();
    void printLevel(GraphicalUI* gui);
    void setButton();

    int getLastInput() const;

    void resizeCharacter(GraphicalUI* gui, QLabel*, QLabel*);

    void onMyButtonClick(int number);

    void clear();

    QVector<QVector<QPixmap*>> textureList{};

    void setTextureAt(int,int,QPixmap*);

    void nextMove(int i);

    void clean();

    void setProgressBar();


    DungeonCrawler *getDc() const;

    void setDc(DungeonCrawler *newDc);

private:
    Ui::MainWindowGame*ui;
    QVector<Button*>buttons;
    bool hasNewInput = false;
    int lastInput;
    GraphicalUI* gui;
    DungeonCrawler* dc;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
};

#endif // MAINWINDOWGAME_H
