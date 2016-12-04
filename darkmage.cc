//
//  darkmage.cpp
//  cc3kbonus
//
//  Created by ChengQiwei on 2016-12-04.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "darkmage.h"
darkmage::darkmage(int a, int b, int c, int d): pc(a,b,c,"darkmage", d) {
    skill* news = new shadenative;
    skilllist.push_back(news);
}
