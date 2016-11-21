//
//  potion.hpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-21.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#ifndef potion_h
#define potion_h

#include <iostream>
#include "info.h"
#include <string>

class potion: public info{
protected:
    std::string type;
    int effect;
public:
    potion(int eff, std::string typ);
    int geteffect();
    std::string gettype();
    ~potion();
};

#endif
