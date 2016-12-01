//
//  shade.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-19.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "shade.h"
shade::shade(): pc(125,25,25,"shade", 80) {
    skill* news = new shadenative;
    skilllist.push_back(news);
}


