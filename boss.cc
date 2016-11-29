//
//  boss.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-29.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "boss.h"

int boss::level = 1;
int boss::alive = 1;

boss::boss(): npc(300 * level,20 * level ,5 * level,"boss", 5 * level,1){
}
