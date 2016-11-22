#include "cell.h"

void cell::setpos(int r, int c){
	row = r;
	col = c;
}

char cell::gettype() const{
	return type;
}

bool cell::isoccupied() const{
	return occupied;
}

char cell::getchartype() const{
	return chartype;
}

void cell::setchartype(char c, npc* p){
	occupied = 1;
	curchar = p;
	chartype = c;
}
void cell::settype(char c){
	type = c;
}