//
//  vampire.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-19.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "vampire.h"


vampire::vampire(): pc(150,25,25,"vampire", 100) {
    skill* news = new vampirenative;
    skilllist.push_back(news);
}
