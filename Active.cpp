#include "Active.h"
#include "Passive.h"

const vector<Passive*>& Active::getPassivePtrList() const {
    return listOfPassiveObjects;
}

void Active::setPassivePtrList(const vector<Passive*>& passivePtrList) {
    listOfPassiveObjects = passivePtrList;
}


Active::Active()
    : listOfPassiveObjects{} {
}

void Active::activate() {
    for (auto ptr: listOfPassiveObjects) {
        ptr->notify(this);
    }
}
void Active::attach(Passive *passive) {
    for (Passive* tempPtr: listOfPassiveObjects) {
        if (tempPtr == passive) {
            throw std::runtime_error{"Cannot attach"};
        }
    }
    listOfPassiveObjects.push_back(passive);
}

void Active::detach(Passive* passive) {
    for (int i = 0; i < listOfPassiveObjects.size(); ++i) {
        if (listOfPassiveObjects.at(i) == passive) {
            listOfPassiveObjects.erase(listOfPassiveObjects.begin() + i);
        }
    }
}


