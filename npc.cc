//
//  npc.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-19.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "npc.h"
#include <string>
using namespace std;

npc::npc(int h, int a, int d, string t):
hp(h),
atk(a),
def(d),
type(t)
{}

void npc::changehp(int damage){
    hp = hp - damage;
    if(hp < 0){
        hp = 0;
    }
}

void npc::changeatk(int effect){
    atk = atk + effect;
    if(atk < 0){
        hp = 0;
    }
}

void npc::changedef(int effect){
    def = def + effect;
    if(def < 0){
        def = 0;
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

string npc::gettype(){
    return type;
}

npc::~npc(){
}
