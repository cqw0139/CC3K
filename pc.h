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
#include "info.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include "WD.h"
#include "WA.h"
#include "BD.h"
#include "BA.h"
#include "RH.h"
#include "PH.h"

class pc: public info{
protected:
    int hp;
    int atk;
    int def;
    int maxhp;
    int gold;
    int row;
    int col;
    std::string type;
public:
    void usepotion(potion*);
    void setrow(int r);
    void setcol(int c);
    int getrow();
    int getcol();
    int gethp();
    int getatk();
    int getdef();
    std::string gettype();
    void changeatk(int effect);
    void changedef(int effect);
    void beattack(npc*);
    void changehp(int demage);
    void attack(npc*);
    pc(int h, int a, int d, std::string t);
    ~pc();
};

#endif 
