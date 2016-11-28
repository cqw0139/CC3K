#include <iostream>
#include "cell.h"
#include "floor.h"

// create a random row and column
void random(int& r, int& c);

// create the random npc type base on the probability
void randomnpc(int& type);

void randominfo(int& row, int& col, floor& f);

// initialize a pc at a random position
void initpc (floor& f);

// initialize npc at random positions
void initnpc(floor& f);

// initialize dragon and gold
//void initdragon(floor& f);

// initialize the floor
void init(floor& r);

void inittreasure(floor& f);

// move the char by the direction
void move(std::string direction, floor& f);

// auto move the npc
void movenpc(floor& f);

void entercommand(floor& f);

int getscore(floor& f);
