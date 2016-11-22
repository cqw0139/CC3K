//
//  dragonT.hpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-21.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#ifndef __dragonT_h__
#define __dragonT_h__

#include <iostream>
#include <string>
#include "treasure.h"
#include "dragon.h"

class dragontreasure:public treasure{
private:
    dragon* protector;
public:
    dragon* getprotector();
    dragontreasure();
    ~dragontreasure();
};

#endif
