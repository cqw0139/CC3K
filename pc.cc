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
#include <cstdlib>
using namespace std;

pc::pc(int h, int a, int d, string t):
hp(h),
atk(a),
def(d),
type(t),
maxhp(h),
gold(0)
{}

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
    string etype = enermy->gettype();
    float dmg = 0;
    dmg = eatk*100.0/(100.0 + def);
    if((etype == "orc")&&(type == "goblin")){
        dmg = dmg * 1.5;
    }
    dmg = ceil(dmg);
    int miss = rand() % 2;
    if(miss == 0){
        dmg = 0;
    }
    if(etype == "elf"){
        if(type == "drow"){
        }
        else{
            changehp(dmg);
        }
    }
    changehp(dmg);
}

void pc::changehp(int damage){
    hp = hp - damage;
    if(hp < 0){
        hp = 0;
    }
    if(hp > maxhp){
        if(type == "vampire"){
        }
        else{
            hp = maxhp;
        }
    }
}

string pc::gettype(){
    return type;
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
    string etype = enermy->gettype();
    float dmg = 0;
    dmg = atk*100.0/(100.0 + edef);
    if(type == "vampire"){
        if(enermy->gettype() == "dwarf"){
            changehp(5);
        }
        else{
            changehp(-5);
        }
    }
    dmg = ceil(dmg);
    if(etype == "halfling"){
        int miss = rand() % 2;
        if(miss == 0){
            dmg = 0;
        }
    }
    enermy->changehp(dmg);
}

void pc::usepotion(potion* p){
    string typ = p->gettype();
    int effect = p->geteffect();
    if(type == "drow"){
        effect = effect * 1.5;
    }
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
