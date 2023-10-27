#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "AbstractUI.h"


class TerminalUI : public AbstractUI {

public:
    virtual ~TerminalUI() override = default;

    void draw(Level*) override;

    int userInput();
};
#endif // TERMINALUI_H
