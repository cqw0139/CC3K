#ifndef __CELL_H__
#define __CELL_H__
#include "pc.h"
#include "shade.h"
#include "goblin.h"
#include "dwarf.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"
#include "dragonknight.h"
#include "deathknight.h"
#include "RH.h"
#include "BA.h"
#include "BD.h"
#include "PH.h"
#include "WA.h"
#include "WD.h"
#include "dragonT.h"
#include "merchantT.h"
#include "humanT.h"
#include "smallT.h"

class cell
{
	int row, col;
	// use h for horizontal wall, d for door, c for corride, 
	// b for blank, p for place, v for vertial wall
	char type;
	info* curinfo = nullptr;
	// the pointer that occupied the cell
	char chartype = 0;
	// 0 for no occupation, 1 for player, 2 for moving npc, 3 non-moving npc, 4 for boss
	int occupied = 0;
	// inidicate the cell is in the which room;
	int curroom = 0;
	// move state of the cell
	int move = 0;
	// the index for the npc character

public:
	// set the cell position
	void setpos(int r, int c);
	// get the cell type
	char gettype() const;
	// check the cell is occupied or not
	int isoccupied() const;
	// if it is occupied, get the character type
	char getchartype() const;
	// set the character into a cell
	void setchartype(char c, info* newinfo, int type);
	// get the room name
	int getroom() const;
	// check the move state of the cell
	bool getmove() const;
	// get the current info ptr
	info* getinfo() const;
	// set the type of the cell
	void settype(char c);
	// set the room name
	void setroom(int n);
	// set the stair;
	void setstair();
	// move character from this cell
	void movechar();
	// change the move state of the cell
	void changemove();
	// reset the cur move
	void resetmove();
};
#endif
