//
//  drow.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-19.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "drow.h"
drow::drow(): pc(150,25,15,"drow", 200) {
    skill* news = new drownative;
    skilllist.push_back(news);
}
