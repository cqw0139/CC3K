//
//  dragonknight.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-30.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "saber.h"

saber::saber(): pc(180,36,30,"saber", 50) {
    skill* news = new invisibleair;
    skilllist.push_back(news);
}
