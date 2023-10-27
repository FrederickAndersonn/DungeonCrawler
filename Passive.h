#ifndef PASSIVE_H
#define PASSIVE_H

#include "Active.h"

class Passive
{
public:
    Passive();
    virtual bool notify (Active* source)=0;
};

#endif // PASSIVE_H
