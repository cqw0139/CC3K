#ifndef __CELL_H__
#define __CELL_H__
#include "pc.h"
#include "shade.h"
#include "goblin.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"

class cell
{
	int row, col;
	// use h for horizontal wall, d for door, c for corride, 
	// b for blank, p for place, v for vertial wall
	char type;
	char chartype;
	npc* curchar = nullptr;
	bool occupied = 0;

public:
	// set the cell position
	void setpos(int r, int c);
	// get the cell type
	char gettype() const;
	// check the cell is occupied or not
	bool isoccupied() const;
	// if it is occupied, get the character type
	char getchartype() const;
	// set the character into a cell
	void setchartype(char c, npc* p);
	// set the type of the cell
	void settype(char c);
};
#endif