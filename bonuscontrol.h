#include <iostream>
#include "cell.h"
#include "floor.h"

// change string type to int type
string intos(int i);

// create a random row and column
void random(int& r, int& c);

// create the random npc type base on the probability
void randomnpc(int& type, int num);

//
void randominfo(int& row, int& col, floor& f);

// initialize a pc at a random position
void bonusinitpc (floor& f);

// initialize npc at random positions
void bonusinitnpc(floor& f);

// initialize the treasure
void bonusinittreasure(floor& f);

// initialize the stair
void bonusinitstair(floor& f);

// initialize the potion
void bonusinitpotion(floor& f);

// initialize the floor
void bonusinit(floor& r);

// upstair when you move to stair
void bonusupstair(floor& f);

// move the char by the direction
bool bonusmovepc(std::string direction, floor& f);

// move the dead npc on the map
void bonusmovedead(floor& f);

// auto move the npc
void bonusmovenpc(floor& f);

// move the used potion
void bonusmoveusedpotion(floor& f);

// attack the npc
void bonusattack (int direction, floor& f);

// pc use potion
void usepotion(int direction, floor& f);

// return your final score
int getscore(floor& f);

// check pc is dead or not
bool pcdead(floor& f);

// check pc is won or not
bool iswon(floor& f);

// enter command for control
bool command(floor& f);

// print the only map
void printMap(floor &f);

// if there is a given map than set it
void setGivenMap(ifstream& map, floor& f);

// print all the infomation in the current floor
void bonusoutput(floor& f);

// clear the current floor
void clearFloor(floor& f);
