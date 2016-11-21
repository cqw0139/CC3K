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
#include <string>
using namespace std;

pc::pc(int h, int a, int d, string t):
hp(h),
atk(a),
def(d),
type(t){}

int pc::gethp(){
    return hp;
}

int pc::getatk(){
    return atk;
}

int pc::getdef(){
    return def;
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

void pc::changeatk(int effect){
    atk = atk + effect;
    if(atk < 0){
        atk = 0;
    }
}

void pc::changedef(int effect){
    def = def + effect;
    if(def < 0){
        def = 0;
    }
}

void pc::attack(npc* enermy){
    int edef = enermy->getdef();
    float dmg = 0;
    dmg = atk*100.0/(100.0 + edef);
    dmg = ceil(dmg);
    enermy->changehp(dmg);
}

void pc::usepotion(potion* p){
    string typ = p->gettype();
    int effect = p->geteffect();
    if(typ == "RH"){
        changehp(effect);
    }
    else if(typ == "BA"){
        changeatk(effect);
    }
    else if(typ == "BD"){
        changedef(effect);
    }
    else if(typ == "PH"){
        changehp(effect);
    }
    else if(typ == "WA"){
        changeatk(effect);
    }
    else if(typ == "WD"){
        changedef(effect);
    }
    else{
        cout << "impossible!!!" << endl;
    }
}

pc::~pc(){
}
