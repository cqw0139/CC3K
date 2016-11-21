//
//  potion.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-21.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "potion.h"
#include <string>
using namespace std;

potion::potion(int eff, std::string typ):
effect(eff),
type(typ)
{}

string potion::gettype(){
    return type;
}

int potion::geteffect(){
    return effect;
}


potion::~potion(){
}
