//
//  npc.hpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-19.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#ifndef __npc_h__
#define __npc_h__

#include <iostream>
#include <string>
#include "info.h"


class npc: public info{
protected:
    // maxhp of npc
    int maxhp;
    // hp of npc
    int hp;
    // atk of npc
    int atk;
    // def of npc
    int def;
    // row of npc
    int row;
    // col of npc
    int col;
    // gold of npc
    int gold;
    // hostile of npc
    int hostile;
    // type of npc
    std::string type;
public:
    // mutate whether this npc is hostile to pc
    void sethostile(int h);
    // set the row field of npc
    void setrow(int r);
    // set the col field of npc
    void setcol(int c);
    // set the gold field of npc
    void setgold(int g);
    // return the hostile field of npc
    int gethostile() const;
    // return the gold field of npc
    int getgold() const;
    // return the row of npc
    int getrow() const;
    // return the col of npc
    int getcol() const;
    // return the hp of npc
    int gethp() const;
    // return the maxhp of npc
    int getmaxhp() const;
    // return the atk of npc
    int getatk() const;
    // return the def of npc
    int getdef() const;
    // return the bool denote whether this npc is died(HP <= 0)
    bool isdead();
    // return the type of npc
    std::string gettype() override;
    // mutate the atk of npc
    void changeatk(int effect);
    // mutate the def of npc
    void changedef(int effect);
    // mutate the hp of npc
    void changehp(int dmg);
    // ctor of npc except dragon, human and merchant
    npc(int h, int a, int d, std::string t, int g, int host);
    // ctor of npc only for human, merchant and dragon
    npc(int h, int a, int d, std::string t, int host);
    // dtor of npc
    ~npc();
};

#endif
