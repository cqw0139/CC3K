#include <iostream>
#include "floor.h"
using namespace std;

char floor::gettype(int r, int c) const{
	return theFloor[r][c].gettype();
}

void floor::initpc(int r, int c, npc* p){
	theFloor[r][c].setchartype('p', p);
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
				if (j > 70 & j < 73)
					c.settype('h');
				if ((j > 2 && j < 29)||(j > 38 && j < 70))
					c.settype('p');
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
				if ((j > 0 && j < 3) || j == 77)
					c.settype('b');
			}
			if (i == 21)
			{
				if (j == 3 || j == 25 || j == 36 || j == 76)
					c.settype('v');
				if ((j > 3 && j < 25) || (j > 36 && j < 76))
					c.settype('p');
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
	//human h;
	npc* newpc = new human();
	initpc(3, 3, newpc);
}

bool floor::isoccupied(int r, int c) const{
	return theFloor[r][c].isoccupied();
}

char floor::getchartype(int r, int c) const{
	return theFloor[r][c].getchartype();
}

ostream &operator<<(ostream &out, const floor &f){
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 79; ++j)
		{
			if (f.isoccupied(i, j)){
				char c = f.getchartype(i, j);
				if (c == 'p')
					out << "@" ;
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
	return out;
}





