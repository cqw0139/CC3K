//
//  treasure.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-21.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "treasure.h"
#include <string>
using namespace std;

treasure::treasure(int g, std::string t): goldvalue(g), 
type(t) {}

string treasure::gettype(){
    return type;
}

int treasure::getvalue(){
    return goldvalue;
}

treasure::~treasure(){
}
