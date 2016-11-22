//
//  npc.hpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-19.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#ifndef npc_h
#define npc_h

#include <iostream>
#include <string>
#include "info.h"


class npc: public info{
protected:
    int hp;
    int atk;
    int def;
    int row;
    int col;
    std::string type;
public:
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
    void changehp(int dmg);
    npc(int h, int a, int d, std::string t);
    ~npc();
};

#endif
