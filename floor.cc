
#include <iostream>
#include <string>
#include <vector>
#include "floor.h"
using namespace std;

int floor::curFloor = 1;

floor::~floor(){
}

void floor::clearFloor() {
	numnpc = 0;
	numpotion = 0;
	numtreasure = 0;
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 79; ++j){
			removeinfo(i, j);
			theFloor[i].pop_back();
		}
	}
	curFloor++;
}

char floor::gettype(int r, int c) const{
	return theFloor[r][c].gettype();
}

int floor::isoccupied(int r, int c) const{
	return theFloor[r][c].isoccupied();
}

char floor::getchartype(int r, int c) const{
	return theFloor[r][c].getchartype();
}

int floor::getroom(int r, int c) const{
	return theFloor[r][c].getroom();
}

int floor::getmaxnpc() const{
	return maxnpc;
}

int floor::getnpc() const{
	return numnpc;
}

int floor::getmaxpotion() const{
	return maxpotion;
}

int floor::getpotion() const{
	return numpotion;
}

int floor::getmaxtreasure() const{
	return maxtreasure;
}

int floor::gettreasure() const{
	return numtreasure;
}

bool floor::getmove(int r, int c) const{
	return theFloor[r][c].getmove();
}

info* floor::getinfo(int r, int c) const{
	return theFloor[r][c].getinfo();
}

pc* floor::getpc() const{
    return person;
}

void floor::checkneighbour(int r, int c, int direction, char& ch, int& occ) const{
	switch (direction){
			case 0: {
				r = r - 1;
				ch = gettype(r, c);
				occ = isoccupied(r, c);
				break;
			}
			case 1: {
				r = r + 1;
				ch = gettype(r, c);
				occ = isoccupied(r, c);
				break;
			}
			case 2: {
				c = c - 1;
				ch = gettype(r, c);
				occ = isoccupied(r, c);
				break;
			}
			case 3: {
				c = c + 1;
				ch = gettype(r, c);
				occ = isoccupied(r, c);
				break;
			}
			case 4: {
				r = r - 1;
				c = c - 1;
				ch = gettype(r, c);
				occ = isoccupied(r, c);
				break;
			}
			case 5: {
				r = r + 1;
				c = c - 1;
				ch = gettype(r, c);
				occ = isoccupied(r, c);
				break;
			}
			case 6: {
				r = r - 1;
				c = c + 1;
				ch = gettype(r, c);
				occ = isoccupied(r, c);
				break;
			}
			case 7: {
				r = r + 1;
				c = c + 1;
				ch = gettype(r, c);
				occ = isoccupied(r, c);
				break;
			}
	}
}

void floor::getpcpos(int& x, int& y) const{
	x = person->getrow();
	y = person->getcol();
}

void floor::initpc(int r, int c, pc* p){
	person = p;
	p->setrow(r);
	p->setcol(c);
	theFloor[r][c].setchartype('p', p, 1);
    action += "Player character has spawned.";
}

void floor::init(){
	for (int i = 0; i < 25; ++i)
	{
		theFloor.push_back(vector<cell>());
		for (int j = 0; j < 79; ++j)
		{
			cell c;
			// set the left and right bound
			if(j == 0 || j == 78)
				c.settype('v');
			// set the first and the last row
			if(i == 0 || i == 24){
				if (j > 0 && j < 78)
					c.settype('h');
			}
			// set the second and last second row
			if(i == 1 || i == 23){
				if (j > 0 && j< 78)
					c.settype('b');
			}
			// set the third row
			if (i == 2)
			{
				if (j == 2 || j == 29|| j == 38 || j == 62)
					c.settype('v');
				if ((j > 2 && j < 29)||(j > 38 && j < 62))
					c.settype('h');
				if (j == 1 || (j > 29 && j < 38)||(j > 62 && j < 78))
					c.settype('b');
			}
			if (i == 3)
			{
				if (j == 2 || j == 29|| j == 38 || j == 62)
					c.settype('v');
				if ((j > 2 && j < 29)||(j > 38 && j < 62))
					c.settype('p');
				if (j > 2 && j < 29)
					c.setroom(1);
				if (j > 38 && j < 62)
					c.setroom(2);
				if (j == 1 || (j > 29 && j < 38)||(j > 62 && j < 78))
					c.settype('b');
			}
			if (i == 4)
			{
				if (j == 2 || j == 62 || j == 70)
					c.settype('v');
				if (j == 29 || j == 38)
					c.settype('d');
				if ((j > 2 && j < 29)||(j > 38 && j < 62))
					c.settype('p');
				if (j > 2 && j < 29)
					c.setroom(1);
				if (j > 38 && j < 62)
					c.setroom(2);
				if (j > 29 && j < 38)
					c.settype('c');
				if (j > 62 && j < 70)
					c.settype('h');
				if (j == 1 || (j > 70 && j < 78))
					c.settype('b');
			}
			if (i == 5)
			{
				if (j == 2 || j == 29 || j == 38 || j == 70 || j == 73)
					c.settype('v');
				if (j > 70 && j < 73)
					c.settype('h');
				if ((j > 2 && j < 29)||(j > 38 && j < 70))
					c.settype('p');
				if (j > 2 && j < 29)
					c.setroom(1);
				if (j > 38 && j < 70)
					c.setroom(2);
				if (j == 33)
					c.settype('c');
				if (j == 1 || (j > 29 && j < 33) || 
					(j > 33 && j < 38) || (j > 73 && j < 78))
					c.settype('b');
			}
			// the sixth row
			if (i == 6)
			{
				if (j == 2 || j == 29 || j == 38 || j == 73 || j == 76)
					c.settype('v');
				if (j > 73 && j < 76)
					c.settype('h');
				if ((j > 2 && j < 29)||(j > 38 && j < 73))
					c.settype('p');
				if (j > 2 && j < 29)
					c.setroom(1);
				if (j > 38 && j < 73)
					c.setroom(2);
				if (j == 33)
					c.settype('c');
				if (j == 1 || (j > 29 && j < 33) || 
					(j > 33 && j < 38) || j == 77)
					c.settype('b');
			}
			// the seventh row
			if (i == 7)
			{
				if (j == 2 || j == 29 || j == 38 || j == 60 || j == 76)
					c.settype('v');
				if ((j > 2 && j < 13) || (j > 13 && j < 29) || 
					(j > 38 && j < 43) || (j > 43 && j < 60))
					c.settype('h');
				if (j > 60 && j < 76)
					c.settype('p');
				if (j > 60 && j < 76)
					c.setroom(2);
				if (j == 33)
					c.settype('c');
				if (j == 13 || j == 43)
					c.settype('d');
				if (j == 1 || (j > 29 && j < 33) || 
					(j > 33 && j < 38) || j == 77)
					c.settype('b');
			}
			// the eighth row
			if (i == 8)
			{
				if (j == 60 || j == 76)
					c.settype('v');
				if (j > 60 && j < 76)
					c.settype('p');
				if (j > 60 && j < 76)
					c.setroom(2);
				if (j == 13 || (j > 30 && j < 44))
					c.settype('c');
				if ((j > 0 && j < 13) || (j > 13 && j < 31) || 
					(j > 43 && j < 60) || j == 77)
					c.settype('b');
			}
			// the ninth row
			if (i == 9)
			{
				if (j == 37 || j == 50 || j == 60 || j == 76)
					c.settype('v');
				if ((j > 37 && j < 43)||(j > 43 && j < 50))
					c.settype('h');
				if (j > 60 && j < 76)
					c.settype('p');
				if (j > 60 && j < 76)
					c.setroom(2);
				if (j == 13 || j == 31)
					c.settype('c');
				if (j == 43)
					c.settype('d');
				if ((j > 0 && j < 13) || (j > 13 && j < 31) || 
					(j > 31 && j < 37) || (j > 50 && j < 60) || 
					j == 77)
					c.settype('b');
			}
			// the tenth row
			if (i == 10)
			{
				if (j == 37 || j == 50 || j == 60 || j == 76)
					c.settype('v');
				if ((j > 60 && j < 76) || (j > 37 && j < 50))
					c.settype('p');
				if (j > 60 && j < 76)
					c.setroom(2);
				if (j > 37 && j < 50)
					c.setroom(3);
				if (j == 13 || j == 31)
					c.settype('c');
				if ((j > 0 && j < 13) || (j > 13 && j < 31) || 
					(j > 31 && j < 37) || (j > 50 && j < 60) || j == 77)
					c.settype('b');
			}
			// the eleventh row
			if (i == 11)
			{
				if (j == 37 || j == 50 || j == 76)
					c.settype('v');
				if ((j > 60 && j < 76) || (j > 37 && j < 50))
					c.settype('p');
				if (j > 60 && j < 76)
					c.setroom(2);
				if (j > 37 && j < 50)
					c.setroom(3);
				if ((j > 12 && j < 32) || (j > 52 && j < 60))
					c.settype('c');
				if (j == 60)
					c.settype('d');
				if ((j > 0 && j < 13) || (j > 31 && j < 37) || 
					(j > 50 && j < 53) || j == 77)
					c.settype('b');
			}
			// the twelvth row
			if (i == 12)
			{
				if (j == 37 || j == 50 || j == 60 || j == 76)
					c.settype('v');
				if ((j > 60 && j < 76) || (j > 37 && j < 50))
					c.settype('p');
				if (j > 60 && j < 76)
					c.setroom(2);
				if (j > 37 && j < 50)
					c.setroom(3);
				if (j == 13 || j == 31 || j == 53)
					c.settype('c');
				if ((j > 0 && j < 13) || (j > 13 && j < 31) || 
					(j > 31 && j < 37) || (j > 50 && j < 53) || 
					(j > 53 && j < 60) || j == 77)
					c.settype('b');
			}
			// the tirtheenth row
			if (i == 13)
			{
				if (j == 37 || j == 50 || j == 60 || j == 76)
					c.settype('v');
				if ((j > 37 && j < 43) || (j > 43 && j < 50) ||
					(j > 60 && j < 69) || (j > 69 && j < 76))
					c.settype('h');
				if (j == 13 || j == 31 || j == 53)
					c.settype('c');
				if (j == 43 || j == 69)
					c.settype('d');
				if ((j > 0 && j < 13) || (j > 13 && j < 31) || 
					(j > 31 && j < 37) || (j > 50 && j < 53) || 
					(j > 53 && j < 60) || j == 77)
					c.settype('b');
			}
			if (i == 14)
			{
				if (j == 3 || j == 25)
					c.settype('v');
				if ((j > 3 && j < 13) || (j > 13 && j < 25))
					c.settype('h');
				if (j == 31 || j == 43 || j == 53 || j == 69)
					c.settype('c');
				if (j == 13)
					c.settype('d');
				if ((j > 0 && j < 3) || (j > 25 && j < 31) || 
					(j > 31 && j < 43) || (j > 43 && j < 53) || 
					(j > 53 && j < 69) || (j > 69 && j < 78))
					c.settype('b');
			}
			if (i == 15)
			{
				if (j == 3 || j == 25 || j == 64 || j == 76)
					c.settype('v');
				if ((j > 64 && j < 69) || (j > 69 && j < 76))
					c.settype('h');
				if (j == 31 || j == 43 || j == 53)
					c.settype('c');
				if (j == 69)
					c.settype('d');
				if (j > 3 && j < 25)
					c.settype('p');
				if (j > 3 && j < 25)
					c.setroom(4);
				if ((j > 0 && j < 3) || (j > 25 && j < 31) || 
					(j > 31 && j < 43) || (j > 43 && j < 53) || 
					(j > 53 && j < 64) || j == 77)
					c.settype('b');
			}
			if (i == 16)
			{
				if (j == 3 || j == 25 || j == 64 || j == 76)
					c.settype('v');
				if (j > 30 && j < 54)
					c.settype('c');
				if ((j > 3 && j < 25) || (j > 64 && j < 76))
					c.settype('p');
				if (j > 3 && j < 25)
					c.setroom(4);
				if (j > 64 && j < 76)
					c.setroom(5);
				if ((j > 0 && j < 3) || (j > 25 && j < 31) ||  
					(j > 53 && j < 64) || j == 77)
					c.settype('b');
			}
			if (i == 17)
			{
				if (j == 3 || j == 25 || j == 64 || j == 76)
					c.settype('v');
				if (j == 31 || j == 43)
					c.settype('c');
				if ((j > 3 && j < 25) || (j > 64 && j < 76))
					c.settype('p');
				if (j > 3 && j < 25)
					c.setroom(4);
				if (j > 64 && j < 76)
					c.setroom(5);
				if ((j > 0 && j < 3) || (j > 25 && j < 31) ||  
					(j > 31 && j < 43) || (j > 43 && j < 64) ||
					j == 77)
					c.settype('b');
			}
			if (i == 18)
			{
				if (j == 3 || j == 25 || j == 36 || j == 64 || j == 76)
					c.settype('v');
				if ((j > 36 && j < 43) || (j > 43 && j < 64))
					c.settype('h');
				if (j == 31)
					c.settype('c');
				if (j == 43)
					c.settype('d');
				if ((j > 3 && j < 25) || (j > 64 && j < 76))
					c.settype('p');
				if (j > 3 && j < 25)
					c.setroom(4);
				if (j > 64 && j < 76)
					c.setroom(5);
				if ((j > 0 && j < 3) || (j > 25 && j < 31) ||  
					(j > 31 && j < 36) || j == 77)
					c.settype('b');
			}
			if (i == 19)
			{
				if (j == 3 || j == 25 || j == 36 || j == 76)
					c.settype('v');
				if (j == 31)
					c.settype('c');
				if ((j > 3 && j < 25) || (j > 36 && j < 76))
					c.settype('p');
				if (j > 3 && j < 25)
					c.setroom(4);
				if (j > 36 && j < 76)
					c.setroom(5);
				if ((j > 0 && j < 3) || (j > 25 && j < 31) ||  
					(j > 31 && j < 36) || j == 77)
					c.settype('b');
			}
			if (i == 20)
			{
				if (j == 3 || j == 76)
					c.settype('v');
				if (j == 25 || j == 36)
					c.settype('d');
				if (j > 25 && j < 36)
					c.settype('c');
				if ((j > 3 && j < 25) || (j > 36 && j < 76))
					c.settype('p');
				if (j > 3 && j < 25)
					c.setroom(4);
				if (j > 36 && j < 76)
					c.setroom(5);
				if ((j > 0 && j < 3) || j == 77)
					c.settype('b');
			}
			if (i == 21)
			{
				if (j == 3 || j == 25 || j == 36 || j == 76)
					c.settype('v');
				if ((j > 3 && j < 25) || (j > 36 && j < 76))
					c.settype('p');
				if (j > 3 && j < 25)
					c.setroom(4);
				if (j > 36 && j < 76)
					c.setroom(5);
				if ((j > 0 && j < 3) || (j > 25 && j < 36) || 
					j == 77)
					c.settype('b');
			}
			if (i == 22)
			{
				if (j == 3 || j == 25 || j == 36 || j == 76)
					c.settype('v');
				if ((j > 3 && j < 25) || (j > 36 && j < 76))
					c.settype('h');
				if ((j > 0 && j < 3) || (j > 25 && j < 36) || 
					j == 77)
					c.settype('b');
			}
			c.setpos(i, j);
			theFloor[i].push_back(c);
		}
	}
	maxnpc = 20;
	maxpotion = 10;
}


void floor::addinfo(int r, int c, info* newinfo){
	//theNpc.emplace_back(newinfo);
	//newnpc->setrow(r);
	//newnpc->setcol(c);
	string type = newinfo->gettype();
	//cout << type << endl;
	if (type == "human"){
		theFloor[r][c].setchartype('H', newinfo, 2);
		numnpc++;
	}
	if (type == "dwarf"){
		theFloor[r][c].setchartype('d', newinfo, 2);
		numnpc++;
	}
	if (type == "halfling"){
		theFloor[r][c].setchartype('L', newinfo, 2);
		numnpc++;
	}
	if (type == "elf"){
		theFloor[r][c].setchartype('e', newinfo, 2);
		numnpc++;
	}
	if (type == "orc"){
		theFloor[r][c].setchartype('o', newinfo, 2);
		numnpc++;
	}
	if (type == "merchant"){
		theFloor[r][c].setchartype('m', newinfo, 2);
		numnpc++;
	}
	if (type == "dragon"){
		theFloor[r][c].setchartype('D', newinfo, 3);
		numnpc++;
	}
	if (type == "WA" || type == "WD" || type == "RH" ||
		type == "PH" || type == "BA" || type == "BD"){
		theFloor[r][c].setchartype('P', newinfo, 4);
		numpotion++;
	}
	if (type == "T")
		theFloor[r][c].setchartype('T', newinfo, 6);
    if (type == "G"){
        theFloor[r][c].setchartype('G', newinfo, 5);
    }
}


void floor::initstair(int r, int c){
	theFloor[r][c].setstair();
}

void floor::movechar(int direction){
    int row = person->getrow();
    int col = person->getcol();
    char ch;
    int occ;
    checkneighbour(row, col, direction, ch, occ);
    if (ch == 'v' || ch == 'h' || ch == 'b')
    {
        cout << "zhuang le" << endl;
    }
    else if (occ == 5) {
        theFloor[row][col].movechar();
        if (direction == 0){
            row--;
        }
        else if (direction == 1){
            row++;
        }
        else if (direction == 2){
            col--;
        }
        else if (direction == 3){
            col++;
        }
        else if (direction == 4){
            col--;
            row--;
        }
        else if (direction == 5){
            row++;
            col--;
        }
        else if (direction == 6){
            row--;
            col++;
        }
        else if (direction == 7){
            row++;
            col++;
        }
        pickgold(row, col);
        removeinfo(row,col);
        theFloor[row][col].setchartype('p', person, 1);
        person->setrow(row);
        person->setcol(col);
    }else if((occ == 6)||(occ == 5)){
        int r = 0;
        int c = 0;
        if(direction == 0) {
            r = row - 1;
            c = col;
        }else if(direction == 1){
            r = row + 1;
            c = col;
        }else if(direction == 2){
            r = row;
            c = col - 1;
        }else if(direction == 3){
            r = row;
            c = col + 1;
        }else if(direction == 4){
            r = row - 1;
            c = col - 1;
        }else if(direction == 5){
            r = row + 1;
            c = col - 1;
        }else if(direction == 6){
            r = row - 1;
            c = col + 1;
        }else if(direction == 7){
            r = row + 1;
            c = col + 1;
        }
        info* curinfo = theFloor[r][c].getinfo();
        dragontreasure* dt = static_cast<dragontreasure*>(curinfo);
        int check = dt->check();
        if(check == 1){
            cout << "da long qu" << endl;
        }else{
            theFloor[row][col].movechar();
            if (direction == 0){
                row--;
            }
            else if (direction == 1){
                row++;
            }
            else if (direction == 2){
                col--;
            }
            else if (direction == 3){
                col++;
            }
            else if (direction == 4){
                col--;
                row--;
            }
            else if (direction == 5){
                row++;
                col--;
            }
            else if (direction == 6){
                row--;
                col++;
            }
            else if (direction == 7){
                row++;
                col++;
            }
            pickgold(row, col);
            removeinfo(row,col);
            theFloor[row][col].setchartype('p', person, 1);
            person->setrow(row);
            person->setcol(col);
        }
    }
    else if (occ == 9) {
			throw (occ);
    }
    else if (occ == 2 || occ == 3){
        cout << "da a" << endl;
    }
    else
    {
        theFloor[row][col].movechar();
        if (direction == 0){
            row--;
        }
        else if (direction == 1){
            row++;
        }
        else if (direction == 2){
            col--;
        }
        else if (direction == 3){
            col++;
        }
        else if (direction == 4){
            col--;
            row--;
        }
        else if (direction == 5){
            row++;
            col--;
        }
        else if (direction == 6){
            row--;
            col++;
        }
        else if (direction == 7){
            row++;
            col++;
        }
        theFloor[row][col].setchartype('p', person, 1);
        person->setrow(row);
        person->setcol(col);
    }
}

void floor::movenpc(int r, int c, int direction){
		if (direction < 0) return;
		info* cur = getinfo(r, c);
		char type = getchartype(r, c);
		theFloor[r][c].movechar();
		switch (direction){
			case 0: {
				r = r - 1;
				theFloor[r][c].setchartype(type, cur, 2);
				break;
			}
			case 1: {
				r = r + 1;
				theFloor[r][c].setchartype(type, cur, 2);
				break;
			}
			case 2: {
				c= c - 1;
				theFloor[r][c].setchartype(type, cur, 2);
				break;
			}
			case 3: {
				c = c + 1;
				theFloor[r][c].setchartype(type, cur, 2);
				break;
			}
			case 4: {
				r = r - 1;
				c = c - 1; 
				theFloor[r][c].setchartype(type, cur, 2);
				break;
			}
			case 5: {
				r = r + 1;
				c = c - 1; 
				theFloor[r][c].setchartype(type, cur, 2);
				break;
			}
			case 6: {
				r = r - 1;
				c = c + 1; 
				theFloor[r][c].setchartype(type, cur, 2);
				break;
			}
			case 7: {
				r = r + 1;
				c = c + 1; 
				theFloor[r][c].setchartype(type, cur, 2);
				break;
			}
		}
		theFloor[r][c].changemove();
}

void floor::removeinfo(int r, int c){
	theFloor[r][c].movechar();
	//numnpc--;
}

void floor::changemove(int r, int c){
	theFloor[r][c].changemove();
}

void floor::attacknpc(int r, int c){
    int p = theFloor[r][c].isoccupied();
    info* curinfo = theFloor[r][c].getinfo();
    npc* curnpc = static_cast<npc*>(curinfo);
    char etyp = getchartype(r,c);
    action = etyp;
    if((p != 2)&&(p != 3))
        action = "You need to attack a valid obeject.";
    else{
        if((etyp == 'm')&&(merchanthostile == 0)){
            merchant* curm = static_cast<merchant*>(curnpc);
            curm->hostile = 1;
            MerchantStartAttack();
        }
        person->attack(curnpc, action);
        action += " ";
    }
}

void floor::npcattack(int r, int c){
    int p = isoccupied(r, c);
    info* curinfo = theFloor[r][c].getinfo();
    npc* curnpc = static_cast<npc*>(curinfo);
    char etyp = getchartype(r,c);
    if((p != 2))
        cout << "??????" << endl;

    else if (curnpc->gethostile())
    {
        action = action + etyp;
        person->beattack(curnpc, action);
        action += " ";
        changemove(r, c);
    }
}

void floor::usepotion(int r, int c){
    int p = isoccupied(r,c);
    info* curinfo = theFloor[r][c].getinfo();
    potion* curpotion = static_cast<potion*>(curinfo);
    if(p != 4)
        cout << "nimabi" << endl;
    else
    {
        person->usepotion(curpotion);
        curpotion->beused();
    }
}

void floor::pickgold(int r, int c){
    int p = isoccupied(r, c);
    info* curinfo = theFloor[r][c].getinfo();
    treasure* curT = static_cast<treasure*>(curinfo);
    if(p != 5 && p != 6){
        cout << "ni bu yao gao shi qing a" << endl;
    }else{
        int g = curT->getvalue();
        person->changegold(g);
    }
}

void floor::MerchantStartAttack(){
    for (int i = 0; i < 25; ++i)
    {
        for (int j = 0; j < 79; ++j)
        {
            char c = getchartype(i, j);
            if (c == 'm'){
                info* in = getinfo(i, j);
                npc* n = static_cast<npc*>(in);
                n->sethostile(1);
            }
        }
    }
}

void floor::changemhost(){
    merchanthostile = 1;
}

ostream &operator<<(ostream &out, floor &f){
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 79; ++j)
		{
			if (f.isoccupied(i, j)){
				char c = f.getchartype(i, j);
				switch (c){
					case 'p':{
						out << "@";
						break;
					}
					case 'L':{
						out << "L";
						break;
					}
					case 'd':{
						out << "d";
						break;
					}
					case 'H':{
						out << "H";
						break;
					}
					case 'e':{
						out << "e";
						break;
					}
					case 'o':{
						out << "o";
						break;
					}
					case 'm':{
						out << "m";
						break;
					}
					case '\\':{
						out << "\\";
						break;
					}
					case 'T':{
						out << "G";
						break;
					}
					case 'D':{
						out << "D";
						break;
					}
					case 'P':{
						out << "P";
						break;
					}
					case 'G':{
                        out << "G";
                        break;
                    }

				}
			}
			else{
				char c = f.gettype(i, j);
				switch (c){
					case 'h':{
						out << "-";
						break;
					}
					case 'd':{
						out << "+";
						break;
					}	
					case 'c':{
						out << "#";
						break;
					}
					case 'b':{
						out << " ";
						break;
					}
					case 'p':{
						out << ".";
						break;
					}
					case 'v':{
						out << "|";
						break;
					}
				}
			}
		}
		out << endl;
	}
	out << "Race: " << f.person->gettype() << " " << "Gold: " << f.person->getgold();
	out << "                " << "floor: " << f.curFloor << endl;
	out << "HP: " << f.person->gethp() << endl;
	out << "Atk: " << f.person->getatk() << endl;
	out << "Def: " << f.person->getdef() << endl;
    out << "Action: " << f.action << endl;
    f.resetaction();
	return out;
}

void floor::resetaction(){
    action = "";
}
