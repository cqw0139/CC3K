//
//  boss.hpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-29.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#ifndef boss_h
#define boss_h

#include <iostream>
#include "npc.h"

class boss: public npc{
public:
    static int level;
    static int alive;
    boss();
    ~boss();
};



#endif
