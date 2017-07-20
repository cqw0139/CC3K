//
//  pc.hpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-19.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#ifndef __pc_h__
#define __pc_h__

#include <iostream>
#include <string>
#include <vector>
#include "info.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include "boss.h"
#include "shadenative.h"
#include "vampirenative.h"
#include "goblinnative.h"
#include "drownative.h"
#include "trollnative.h"
#include "deathknative.h"
#include "invisibleair.h"
#include "excalibur.h"
#include "bloodrage.h"
#include "handofMidas.h"
#include "grow.h"
#include "poisonbody.h"
#include "luckyseven.h"
#include "print.h"
#include "frostmourne.h"
#include "WD.h"
#include "WA.h"
#include "BD.h"
#include "BA.h"
#include "RH.h"
#include "PH.h"



class pc: public info{
protected:
    // the maximum hp of pc
    int maxmp;
    // mp of pc
    int mp;
    // exp of pc
    int exp;
    // level of pc
    int level;
    // hp of pc
    int hp;
    // atk of pc
    int atk;
    // def o pc
    int def;
    // the hp raise when pc level up
    int hpup;
    // the atk raise when pc level up
    int atkup;
    // the def raise when pc level up
    int defup;
    // the maxhp raise when pc level up
    int maxhp;
    // the gold of pc
    int gold;
    // the row position of pc
    int row = 0;
    // the col position of pc
    int col = 0;
    // the type of pc
    std::string type;
    // the list skills that pc owns
    std::vector<skill*> skilllist;
public:
    // check whether death knight has used its talent skill
    static int deathk;
    // pc use the potion it consume
    void usepotion(potion*, std::string &action);
    // set the row field of pc
    void setrow(int r);
    // set the col field of pc
    void setcol(int c);
    // add exp to pc
    void addexp(int e);
    // change the level filed of pc
    void changelevel(int l);
    // change the mp field to pc
    void changemp(int m);
    // check whether pc is full of exp and let pc level up
    void levelup(std::string& action);
    // return the mp field of pc
    int getmp();
    // return the exp field of pc
    int getexp();
    // return the level field of pc
    int getlevel();
    // return the row field of pc
    int getrow() const;
    // return the col field of pc
    int getcol() const;
    // return the hp field of pc
    int gethp() const;
    // return the atk field of pc
    int getatk() const;
    // return the def field of pc
    int getdef() const;
    // return the gold field of pc
    int getgold() const;
    // return a bool that whether pc is died(HP <= 0)
    bool isdead(std::string &action);
    // return the type of pc
    std::string gettype() override;
    // return 1 if pc has the skill
    int check(std::string s);
    // mutate the atk field of pc
    void changeatk(int effect);
    // mutate the def field of pc
    void changedef(int effect);
    // pc all a npc class to attack it
    void beattack(npc*, std::string& action);
    // mutate the hp field of pc
    void changehp(int demage);
    // pc call a npc class to attack it
    void attack(npc*, std::string& action);
    // mutate the gold field of pc
    void changegold(int earn);
    // pc do the natural restore at the end of each turn
    void naturalrestore();
    // pc use 50 mp to exchange 50 hp
    void cure(std::string& action);
    // ctor of nullptr pc
    pc();
    // normal ctor of pc
    pc(int h, int a, int d, std::string t, int m);
    // dtor of pc
    ~pc();
};

#endif 
