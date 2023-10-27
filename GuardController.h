#ifndef GUARDCONTROLLER_H
#define GUARDCONTROLLER_H
#include "AbstractController.h"
#include <string>
#include <vector>

class GuardController : public AbstractController {


public:
    GuardController(std::vector<int>);

private:
    virtual int move() override;

    std::vector<int> pattern;
};

#endif // GUARDCONTROLLER_H
