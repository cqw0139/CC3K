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

int pc::deathk = 0;

string itos(int i)  // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}

pc::pc(int h, int a, int d, string t, int m): maxmp(m), level(1), mp(m), exp(0), hp(h), atk(a), def(d), type(t), maxhp(h), gold(0) {
    defup=0.2*d;
    atkup=0.2*a;
    hpup=0.2*h;
}

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
    if(mp > maxmp){
        mp = maxmp;
    }
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
        maxhp += hpup;
        changehp(-hpup);
        action += " PC increases " + itos(hpup) + " maxHP, and restores " + itos(hpup) + " HP.";
        changeatk(atkup);
        action += " PC increases " + itos(atkup) + " ATK.";
        changedef(defup);
        action += " PC increases " + itos(defup) + " DEF.";
        if(level == 4){
            if(type == "vampire"){
                printPowerUp();
                action += " PC Race Up !!! PC changes race to Bloodseeker right now.";
                type = "Bloodseeker";
                level = 1;
                exp = 0;
                skill* news = new bloodrage;
                skilllist.push_back(news);
                action += " PC learns a new skill Bloodrage.";
            }else if(type == "goblin"){
                printPowerUp();
                action += " PC Race Up !!! PC changes race to Alchemist right now.";
                type = "Alchemist";
                level = 1;
                exp = 0;
                skill* news = new handofMidas;
                skilllist.push_back(news);
                action += " PC learns a new skill handofMidas.";
            }else if(type == "troll"){
                printPowerUp();
                action += " PC Race Up !!! PC changes race to Devil right now.";
                type = "Devil";
                level = 1;
                exp = 0;
                skill* news = new grow;
                skilllist.push_back(news);
                action += " PC learns a new skill grow.";
            }else if(type == "drow"){
                printPowerUp();
                action += " PC Race Up !!! PC changes race to Venomancer right now.";
                type = "Venomancer";
                level = 1;
                exp = 0;
                skill* news = new poisonbody;
                skilllist.push_back(news);
                action += " PC learns a new skill poisonbody.";
            }else if(type == "shade"){
                printPowerUp();
                action += " PC Race Up !!! PC changes race to Dark Mage right now.";
                type = "Dark Mage";
                level = 1;
                exp = 0;
                skill* news = new luckyseven;
                skilllist.push_back(news);
                action += " PC learns a new skill luckyseven.";
            }else if(type == "deathknight"){
                printPowerUp();
                action += " PC Race Up !!! PC changes race to Lich King right now.";
                type = "Lich King";
                level = 1;
                exp = 0;
                skill* news = new frostmourne;
                skilllist.push_back(news);
                action += " PC learns a new skill frostmourne.";
            }else if(type == "saber"){
                printPowerUp();
                action += " PC Race Up !!! PC changes race to Royal Saber right now.";
                type = "Royal Saber";
                level = 1;
                exp = 0;
                skill* news = new excalibur;
                skilllist.push_back(news);
                action += " PC learns a new skill excalibur.";
            }
        }
    }
}

void pc::beattack(npc* enermy, string& action){
    int length = action.length();
    string etyp = &action[length-1];
    action.pop_back();
    action += " ";
    int eatk = enermy->getatk();
    string etype = enermy->gettype();
    float dmg = 0;
    dmg = eatk*100.0/(100.0 + def);
    if((etype == "orc")&&(check("goblinnative") == 1)){
        dmg = dmg * 1.5;
    }
    dmg = ceil(dmg);
    int miss = rand() % 2;
    string d = "";
    if(miss == 0){
        dmg = 0;
        action = action + etyp + " attacks miss.";
    }else{
        if(check("invisibleair") == 1){
            if(dmg<=5) {
                d = itos(dmg - 1);
                dmg = 1;
                action += "Invisible air protects PC and reduces " + d + " damages. ";
            }else{
                dmg -= 5;
                action += "Invisible air protects PC and reduces 5 damages. ";
            }
        }
        d = itos(dmg);
        action = action + etyp + " deals " + d + " damage to PC.";
        if(check("poisonbody") == 1){
            enermy->changehp(5);
            action = action + " " + etyp + " loses 5 HP since it touches PC's poisonbody(" + itos(enermy->gethp()) + " HP).";
        }
    }
    changehp(dmg);
    if(dmg > 0){
        addexp(3);
    }
    dmg = eatk*100.0/(100.0 + def);
    if(etype == "elf"){
        if(check("drownative") == 1){
        }
        else{
            miss = rand() % 2;
            if(miss == 0){
                dmg = 0;
                action = action + " " + etyp + " attacks miss.";
            }else{
                if(check("invisibleair") == 1){
                    if(dmg<=5) {
                        d = itos(dmg - 1);
                        dmg = 1;
                        action += " Invisible air protects PC and reduces " + d + " damages.";
                    }else{
                        dmg -= 5;
                        action += " Invisible air protects PC and reduces 5 damages.";
                    }
                }
                d = itos(dmg);
                action = action + " " + etyp + " deals " + d + " damage to PC.";
                if(check("poisonbody") == 1){
                    enermy->changehp(5);
                    action = action + " " + etyp + " loses 5 HP since it touches PC's poisonbody(" + itos(enermy->gethp()) + " HP).";
                }
            }
            changehp(dmg);
            if(dmg > 0){
                addexp(3);
            }
        }
    }
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
    if(check("vampirenative") == 1){
        if(enermy->gettype() == "dwarf"){
            changehp(5);
        }
        else{
            action = action + " PC gain 5 HP by vampire's talent.";
            changehp(-5);
        }
    }
    if(check("goblinnative") == 1){
        changegold(5);
        action = action + " PC steals 5 golds by goblin's talent.";
    }
    dmg = ceil(dmg);
    string h;
    int miss = rand() % 2;
    if(check("luckyseven") == 1){
        int luckynum = 0;
        luckynum = rand() % 7 + 1;
        if(luckynum == 7){
            enermy->changehp(99999);
            action = action + " LUCKY SEVEN!!!!! PC kills "+ etype +" immediately!";
        }else{
            if((miss == 0)&&(etype == "halfling")){
                dmg = 0;
                action = action + " PC attacks miss.";
            }else{
                int exca = 0;
                exca = rand() % 7 + 1;
                if(check("frostmourne") == 1){
                    dmg = (atk*100.0)/100.0;
                }else if((check("excalibur") == 1)&&(exca == 7)){
                    dmg = 3 * dmg;
                }
                string d = itos(dmg);
                enermy->changehp(dmg);
                h = itos(enermy->gethp());
                if(check("frostmourne") == 1){
                    action += " PC deals " + d + " damage to " + etyp + " (" + h + " HP) by FrostMourne.";
                }else if((check("excalibur") == 1)&&(exca == 7)){
                    action = action + " EXCALIBUR!!!!!" + " PC deals " + d + " damage to " + etyp + " (" + h + " HP) and restores " + d + " HP by Excalibur.";
                    changehp(-dmg);
                }else{
                    action = action + " PC deals " + d + " damage to " + etyp + " (" + h + " HP).";
                }
            }
        }
    }else{
        if((miss == 0)&&(etype == "halfling")){
            dmg = 0;
            action = action + " PC attacks miss.";
        }else{
            int exca = 0;
            exca = rand() % 7 + 1;
            if(check("frostmourne") == 1){
                dmg = (atk*100.0)/100.0;
            }else if((check("excalibur") == 1)&&(exca == 7)){
                dmg = 3 * dmg;
            }
            string d = itos(dmg);
            enermy->changehp(dmg);
            h = itos(enermy->gethp());
            if(check("frostmourne") == 1){
                action += " PC deals " + d + " damage to " + etyp + " (" + h + " HP) by FrostMourne.";
            }else if((check("excalibur") == 1)&&(exca == 7)){
                action = action + " EXCALIBUR!!!!!" + " PC deals " + d + " damage to " + etyp + " (" + h + " HP) and restores " + d + " HP by Excalibur.";
                changehp(-dmg);
            }else{
                action = action + " PC deals " + d + " damage to " + etyp + " (" + h + " HP).";
            }
        }
    }
    addexp(5);
/*    if(check("bloodslash") == 1){
        action = action + " BLOOD SLASH!!!";
        changehp(-dmg);
    }*/
}

void pc::usepotion(potion* p, string &action){
    string typ = p->gettype();
    int effect = p->geteffect();
    action = " PC uses " + typ + ".";
    if(check("drownative") == 1){
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

int pc::check(string s){
    int length = skilllist.size();
    for(int i = 0; i < length; i++){
        if(skilllist[i]->getname() == s){
            return 1;
        }
    }
    return 0;
}

void pc::naturalrestore(){
    changemp(5);
    if(check("trollnative") == 1){
        changehp(-5);
    }
}

bool pc::isdead(string &action){
    if(check("deathknative") == 1){
        if(deathk == 0){
            if(gethp() <= 0){
                action = action + " PC returns from the death and restores 100 HP by deathknight's talent.";
                changehp(-100);
                deathk = 1;
            }
        }
    }
    return gethp() > 0;
}

void pc::cure(string& action){
    action += " PC uses cure and restores 50 HP.";
    mp = 0;
    changehp(-50);
}

pc::pc(){
}

pc::~pc(){
}
