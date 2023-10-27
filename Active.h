#ifndef ACTIVE_H
#define ACTIVE_H

#include <stdexcept>
#include <vector>

using std::vector;

class Passive;

class Active {

protected:
    vector<Passive*> listOfPassiveObjects;


public:
    Active();
    virtual void attach(Passive*) ;
    virtual void detach(Passive*) ;
    virtual void activate();
    const vector<Passive*>& getPassivePtrList() const;

    void setPassivePtrList(const vector<Passive*>& passivePtrList);
};


#endif // ACTIVE_H
