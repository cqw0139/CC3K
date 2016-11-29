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
#include <sstream>
using namespace std;


string itos(int i)  // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}

pc::pc(){}

pc::pc(int h, int a, int d, string t, int m):level(1), mp(m), exp(0), hp(h), atk(a), def(d), type(t), maxhp(h), gold(0) {}

void pc::setrow(int r){
    row = r;
}
void pc::setcol(int c){
    col = c;
}

void pc::addexp(int e){
    exp += e;
}
void pc::changelevel(int l){
    level += l;
}
void pc::changemp(int m){
    mp += m;
}
int pc::getmp(){
    return mp;
}
int pc::getexp(){
    return exp;
}
int pc::getlevel(){
    return level;
}

int pc::getrow() const{
    return row;
}

int pc::getcol() const{
    return col;
}

int pc::gethp() const{
    return hp;
}

int pc::getatk() const{
    return atk;
}

int pc::getdef() const{
    return def;
}

void pc::levelup(string& action){
    while(exp >= 100){
        exp -= 100;
        level++;
        action += " Congratulation! PC LEVEL UP!!!";
        maxhp = maxhp * 1.2;
        atk = atk*1.2;
        def = def*1.2;
        changehp(-maxhp);
    }
}

void pc::beattack(npc* enermy, string& action){
    int length = action.length();
    string etyp = &action[length-1];
    action.pop_back();
    action += " ";
    action += etyp;
    int eatk = enermy->getatk();
    string etype = enermy->gettype();
    action = action + " deals ";
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
    string d = itos(dmg);
    action = action + d + " damage to PC.";
    if(etype == "elf"){
        if(type == "drow"){
        }
        else{
            miss = rand() % 2;
            if(miss == 0){
                dmg = 0;
            }
            d = itos(dmg);
            action = action + " " + etyp + " deals " + d + " damage to pc.";
            changehp(dmg);
            addexp(3);
        }
    }
    changehp(dmg);
    addexp(3);
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

int pc::getgold() const{
    return gold;
}

void pc::changegold(int earn){
    gold = gold + earn;
}

void pc::attack(npc* enermy, string& action){
    int edef = enermy->getdef();
    string etype = enermy->gettype();
    float dmg = 0;
    string etyp = action;
    action.pop_back();
    dmg = atk*100.0/(100.0 + edef);
    if(type == "vampire"){
        if(enermy->gettype() == "dwarf"){
            changehp(5);
        }
        else{
            action = action + " PC gain 5 HP by vampire's skill.";
            changehp(-5);
        }
    }
    if(type == "goblin"){
        changegold(5);
        action = action + " PC steals 5 golds by goblin's skill.";
    }
    dmg = ceil(dmg);
    if(etype == "halfling"){
        int miss = rand() % 2;
        if(miss == 0){
            dmg = 0;
        }
    }
    string d = itos(dmg);
    enermy->changehp(dmg);
    addexp(5);
    string h = itos(enermy->gethp());
    action = action + " PC deals " + d + " damage to " + etyp + " (" + h + " HP).";
}

void pc::usepotion(potion* p, string &action){
    string typ = p->gettype();
    int effect = p->geteffect();
    action = " PC uses " + typ + ".";
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
        action += "there is a bug.";
    }
}

bool pc::isdead() const{
    return gethp() > 0;
}

pc::~pc(){
}
