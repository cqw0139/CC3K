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
    pc* p1 = new shade;
    //pc* p2 = new goblin;
    potion* a = new RH;
    npc* n1 = new halfling;
    cout << n1->gethp() << endl;
    p1->attack(n1);
    
    cout << n1->gethp() << endl;
    p1->usepotion(a);
    cout << n1->gethp() << endl;
    p1->attack(n1);
    
    cout << n1->gethp() << endl;
    p1->usepotion(a);
    cout << n1->gethp() << endl;
    p1->attack(n1);
    
    cout << n1->gethp() << endl;
    p1->usepotion(a);
    cout << n1->gethp() << endl;
    p1->attack(n1);
    
    cout << n1->gethp() << endl;
    p1->usepotion(a);
    cout << n1->gethp() << endl;
    p1->attack(n1);
    
    cout << n1->gethp() << endl;
    p1->usepotion(a);
    cout << n1->gethp() << endl;
    p1->attack(n1);
    
    cout << n1->gethp() << endl;
    p1->usepotion(a);
    cout << n1->gethp() << endl;
    /*cout << p2->gethp() << endl;
    p2->beattack(n1);
    cout << p2->gethp() << endl;
    p2->usepotion(a);
    cout << p2->gethp() << endl;*/
}
