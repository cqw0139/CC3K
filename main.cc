//
//  main.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-19.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "shade.h"
#include "goblin.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"



using namespace std;

int main(int argc, const char * argv[]) {
    pc* p = new shade;
    potion* a = new WD;
    cout << p->gethp() << endl;
    cout << p->getatk() << endl;
    cout << p->getdef() << endl;
    p->usepotion(a);
    cout << p->gethp() << endl;
    cout << p->getatk() << endl;
    cout << p->getdef() << endl;
}
