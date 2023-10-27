#include "GuardController.h"


GuardController::GuardController(std::vector<int> initVec) : pattern(initVec) {
}

int GuardController::move() {

    int tempInt = pattern.at(0);
    pattern.erase(pattern.begin());
    pattern.push_back(tempInt);
    return tempInt;
}
