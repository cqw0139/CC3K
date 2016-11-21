//
//  pc.hpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-19.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#ifndef pc_h
#define pc_h

#include <iostream>
#include "info.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

class pc: public info{
protected:
    int hp;
    int atk;
    int def;
public:
    int gethp();
    int getatk();
    int getdef();
    void changeatk();
    void changedef();
    void beattack(npc*);
    void changehp(int demage);
    void attack(npc*);
    pc(int h, int a, int d);
    ~pc();
};

#endif 
