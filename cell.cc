#include "cell.h"

void cell::setpos(int r, int c){
	row = r;
	col = c;
}

char cell::gettype() const{
	return type;
}

int cell::isoccupied() const{
	return occupied;
}

char cell::getchartype() const{
	return chartype;
}

int cell::getroom() const{
	return curroom;
}

info* cell::getinfo() const{
	return curinfo;
}

bool cell::getmove() const{
	return move;
}

void cell::setchartype(char c, info* newinfo, int type){
	occupied = type;
	chartype = c;
	curinfo = newinfo;
	//index = i;
}

void cell::setstair(){
	occupied = 9;
	chartype = '\\';
}

void cell::settype(char c){
	type = c;
}

void cell::setroom(int n){
	curroom = n;
}

void cell::movechar(){
	curinfo = nullptr;
	chartype = 0;
	occupied = 0;
	move = 0;
}

void cell::changemove(){
	move = !move;
}

void cell::resetmove(){
	move = 0;
}

cell::~cell(){
	//delete curinfo;
}
