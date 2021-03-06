#include <iostream>
#include "cell.h"
#include "print.h"
#include "floor.h"
#include "bonuscontrol.h"

// create a random row and column
void random(int& r, int& c);

// create the random npc type base on the probability
void randomnpc(int& type);

//
void randominfo(int& row, int& col, floor& f);

// initialize a pc at a random position
void initpc (floor& f);

// initialize npc at random positions
void initnpc(floor& f);

// initialize the floor
void init(floor& r);

//
void inittreasure(floor& f);

// move the char by the direction
bool move(std::string direction, floor& f);

// auto move the npc
void movenpc(floor& f);

//
void entercommand(floor& f);

//
int getscore(floor& f);

//
void setGivenMap(ifstream& map, floor& f);

//
void output(floor& f);
