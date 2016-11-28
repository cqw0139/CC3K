#ifndef __dragonT_h__
#define __dragonT_h__

#include <iostream>
#include <string>
#include "treasure.h"
//#include "dragon.h"
#include "npc.h"

class dragon;

class dragontreasure: public treasure{
private:
    npc* protector;
    int wheprotect = 1;
public:
    int check();
    void protectdead();
    void setprotector(npc*);
    npc* getprotector();
    dragontreasure();
    ~dragontreasure();
};

#endif