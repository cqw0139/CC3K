//
//  treasure.hpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-21.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#ifndef __treasure_h__
#define __treasure_h__

#include <iostream>
#include <string>
#include "info.h"


class treasure:public info{
private:
    int goldvalue;
    std::string type;
public:
    treasure(int g, std::string t);
    ~treasure();
};

#endif 
