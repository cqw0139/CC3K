//
//  pc.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-19.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "pc.h"
#include <cmath>
#include <iostream>
using namespace std;

pc::pc(int h, int a, int d):
hp(h),
atk(a),
def(d) {}

int pc::gethp(){
    return hp;
}


void pc::beattack(npc* enermy){
    int eatk = enermy->getatk();
    float dmg = 0;
    dmg = eatk*100.0/(100.0 + def);
    dmg = ceil(dmg);
    changehp(dmg);
}

void pc::changehp(int damage){
    hp = hp - damage;
    if(hp < 0){
        hp = 0;
    }
}

void pc::attack(npc* enermy){
    int edef = enermy->getdef();
    float dmg = 0;
    dmg = atk*100.0/(100.0 + edef);
    dmg = ceil(dmg);
    enermy->changehp(dmg);
}

pc::~pc(){
}
