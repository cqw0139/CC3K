#ifndef __merchant_h__
#define __merchant_h__

#include <iostream>
#include "npc.h"

class merchant: public npc{
public:
    static int hostile;
    merchant();
    ~merchant();
};

#endif