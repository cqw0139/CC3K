//
//  skill.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-30.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "skill.h"
#include <string>

using namespace std;

string skill::getname(){
    return name;
}

skill::skill(std::string n, std::string d):
name(n),
description(d)
{}

skill::~skill(){
}
