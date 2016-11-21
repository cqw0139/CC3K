//
//  npc.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-19.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "npc.h"

npc::npc(int h, int a, int d):
hp(h),
atk(a),
def(d) {}

void npc::changehp(int damage){
    hp = hp - damage;
    if(hp < 0){
        hp = 0;
    }
}

int npc::gethp(){
    return hp;
}

int npc::getatk(){
    return atk;
}

int npc::getdef(){
    return def;
}

npc::~npc(){
}
