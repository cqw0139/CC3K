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
    int maxhp;
    int hp;
    int atk;
    int def;
    int row;
    int col;
    int gold;
    int hostile;
    std::string type;
public:
    void sethostile(int h);
    void setrow(int r);
    void setcol(int c);
    void setgold(int g);
    int gethostile() const;
    int getgold() const;
    int getrow() const;
    int getcol() const;
    int gethp() const;
    int getmaxhp() const;
    int getatk() const;
    int getdef() const;
    bool isdead() const;
    std::string gettype() override;
    void changeatk(int effect);
    void changedef(int effect);
    void changehp(int dmg);
    npc(int h, int a, int d, std::string t, int g, int host);
    npc(int h, int a, int d, std::string t, int host);
    ~npc();
};

#endif
