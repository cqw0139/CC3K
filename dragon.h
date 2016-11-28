#ifndef __dragon_h__
#define __dragon_h__

#include <iostream>
#include "npc.h"
#include "dragonT.h"



class dragon: public npc{
    dragontreasure* mybaby;
public:
    void setbaby(dragontreasure*);
    void biebiemybaby();
    dragon();
    ~dragon();
};

#endif