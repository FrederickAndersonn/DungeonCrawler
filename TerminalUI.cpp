#include "TerminalUI.h"
#include "DungeonCrawler.h"
#include "Level.h"
#include "Tile.h"
#include <iostream>
#include <string>


void TerminalUI::draw(Level* level) {
    int usrInput{};
    for (int i = 0; i < level->getMaxRow()+1; i++) {
        for (int j = 0; j < level->getMaxColumn()+1;j++) {
            std::cout << level->veccy.at(i).at(j)->getTexture();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl
              << "Enter Movement: " << std::endl;
    usrInput = userInput();

    if (!std::cin) {
        throw std::runtime_error{"Invalid Input"};
    }
    if (usrInput == 0) {
        return;
    }
    this->getDungeonCrawler()->turn(usrInput);

    draw(level);
}

int TerminalUI::userInput() {
    char temp;

    std::cin >> temp;

    switch (temp) {

        case 'z':
            return 1;
        case 'x':
            return 2;
        case 'c':
            return 3;
        case 'a':
            return 4;
        case 's':
            return 5;
        case 'd':
            return 6;
        case 'q':
            return 7;
        case 'w':
            return 8;
        case 'e':
            return 9;
        default:
            return 5;
    }


    return 0;
}
