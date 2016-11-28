#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "control.h"

void randompc(int &r, int &c){
	r = rand() % 23 + 1;
	c = rand() % 77 + 1;
}

void randomnpc(int& type, int num){
	type = rand() % num;
}

void randominfo(int& row, int& col, floor& f){
	int whichroom;
	whichroom = rand() % 5 + 1;
	// random the row and column
	while(1){ 
		randompc(row, col);
		int state = f.isoccupied(row, col);
		if (state) continue;
		int room = f.getroom(row, col);
		if (room == whichroom) break;
	}
}

void inittreasure(floor& f){
    int row, col;
    int treasuretype;
    treasure* newtreasure;
    int numoftreasure = 0;
    while(1){
        treasuretype = rand() % 8 + 1;
        randominfo(row, col, f);
        if(treasuretype == 1){
            cout << "There is dragon." << endl;
            dragontreasure* dt = new dragontreasure;
            char typ;
            int occ;
            int i;
            while(1){
                i = rand() % 8;
                f.checkneighbour(row, col, i, typ, occ);
                if((typ == 'p')&&(occ == 0)){
                    int r = 0;
                    int c = 0;
                    dragon* newdragon = new dragon;
                    dt->setprotector(newdragon);
                    newdragon->setbaby(dt);
                    if(i == 0) {
                        r = row - 1;
                        c = col;
                    }else if(i == 1){
                        r = row + 1;
                        c = col;
                    }else if(i == 2){
                        r = row;
                        c = col - 1;
                    }else if(i == 3){
                        r = row;
                        c = col + 1;
                    }else if(i == 4){
                        r = row - 1;
                        c = col - 1;
                    }else if(i == 5){
                        r = row + 1;
                        c = col - 1;
                    }else if(i == 6){
                        r = row - 1;
                        c = col + 1;
                    }else if(i == 7){
                        r = row + 1;
                        c = col + 1;
                    }
                    f.addinfo(r,c,newdragon);
                    break;
                }
            }
            newtreasure = dt;
        }
        else if(treasuretype <= 3){
            newtreasure = new streasure;
        }
        else{
            newtreasure = new htreasure;
        }
        f.addinfo(row, col, newtreasure);
        ++numoftreasure;
        if (numoftreasure == 10) break;
    }
}

void initpotion(floor& f){
	srand (time(NULL));
	int row, col;
	int potiontype;
	potion* newpotion;
	while (1) {
		randomnpc(potiontype, 6);
		randominfo(row, col, f);
		switch (potiontype){
			case 0: {
				newpotion = new BA();
				break;
			}
			case 1: {
				newpotion = new BD();
				break;
			}
			case 2: {
				newpotion = new PH();
				break;
			}
			case 3: {
				newpotion = new RH();
				break;
			}
			case 4: {
				newpotion = new WA();
				break;
			}
			case 5: {
				newpotion = new WD();
				break;
			}

		} 
		f.addinfo(row, col, newpotion);
		if (f.getpotion() == f.getmaxpotion()) break;
	}
}

void initpc (floor& f){
	srand (time(NULL));
	int row, col;
	pc* newpc = new vampire();
	randominfo(row ,col, f);
	f.initpc(row, col, newpc);
}

/*void initdragon(floor& f){
	int row, col;
	int room;
	int state;
	char type;
	dragontreasure* newndragontreasure;
	while (1) {
		randompc(row, col);
		room = f.getroom(row, col);
		state = f.isoccupied(row, col);
		if (room && (state == 0)){
			newndragontreasure = new dragontreasure();
			f.addinfo(row, col, newndragontreasure);
			break;
		}
	}
	dragon* newdragon = new dragon();
	while (1){
		int direction = rand() % 4;
		if (direction == 0){
			int newrow = row - 1;
			type = f.gettype(newrow, col);
			state = f.isoccupied(newrow, col);
			if (type == 'p'&& (state == 0)){
				f.addinfo(newrow, col, newdragon);
				break;
			}
		}
		else if (direction == 1){
			int newcol = col + 1;
			type = f.gettype(row, newcol);
			state = f.isoccupied(row, newcol);
			if (type == 'p'&& (state == 0)){
				f.addinfo(row, newcol, newdragon);
				break;
			}
		}
		else if (direction == 2){
			int newrow = row + 1;
			type = f.gettype(newrow, col);
			state = f.isoccupied(newrow, col);
			if (type == 'p'&& (state == 0)){
				f.addinfo(newrow, col, newdragon);
				break;
			}
		}
		else {
			int newcol = col - 1;
			type = f.gettype(row, newcol);
			state = f.isoccupied(row, newcol);
			if (type == 'p'&& (state == 0)){
				f.addinfo(row, newcol, newdragon);
				break;
			}
		}
	}
}*/

void initnpc(floor& f){
	srand (time(NULL));
	int row, col;
	int npctype;
	npc* newnpc;
	while (1) {
		randomnpc(npctype, 18);
		randominfo(row, col, f);
		if (npctype > 13)
			newnpc = new human();
		else if (npctype > 10)
			newnpc = new dwarf();
		else if (npctype > 5)
			newnpc = new halfling();
		else if (npctype > 3)
			newnpc = new elf();
		else if (npctype > 1)
			newnpc = new orc();
		else
			newnpc = new merchant();
		f.addinfo(row, col, newnpc);
		if (f.getnpc() == f.getmaxnpc()) break;
	}
}

void initstair(floor& f){
	srand (time(NULL));
	int row, col;
	randominfo(row, col, f);
	f.initstair(row, col);
}

void init(floor& f){
	f.init();
	initpc(f);
	initpotion(f);
	//initdragon(f);
	initnpc(f);
	initstair(f);
	inittreasure(f);
	cout << f;
}

void upstair(floor& f){
	pc* curpc = f.getpc();
	srand (time(NULL));
	int row, col;
	randominfo(row, col ,f);
	f.initpc(row, col, curpc);
	initpotion(f);
	//initdragon(f);
	initnpc(f);
	initstair(f);
	inittreasure(f);
}

void move(string direction, floor& f){
	if (direction == "no"){
		f.movechar(0);
	}
	else if(direction == "so"){
		f.movechar(1);
	}
	else if(direction == "we"){
		f.movechar(2);
	}
	else if(direction == "ea"){
		f.movechar(3);
	}
	else if(direction == "nw"){
		f.movechar(4);
	}
	else if(direction == "sw"){
		f.movechar(5);
	}
	else if(direction == "ne"){
		f.movechar(6);
	}
	else if(direction == "se"){
		f.movechar(7);
	}
}

void movedead(floor& f){
	for (int i = 1; i < 78; ++i)
	{
		for (int  j= 1; j < 24; ++j)
		{
			int occupied = f.isoccupied(j, i);
			if (occupied == 2)
			{
				info* curinfo = f.getinfo(j, i);
				npc* curnpc = static_cast<npc*>(curinfo);
				bool state = curnpc->isdead();
				if(!state){
                    int g = curnpc->getgold();
                    pc* p = f.getpc();
                    p->changegold(g);
					f.removeinfo(j, i);
				}
            }else if(occupied == 3){
                info* curinfo = f.getinfo(j, i);
                npc* curnpc = static_cast<npc*>(curinfo);
                bool state = curnpc->isdead();
                if(!state){
                    info* curinfo = f.getinfo(j,i);
                    dragon* d = static_cast<dragon*>(curinfo);
                    d->biebiemybaby();
                    f.removeinfo(j, i);
                }
            }
		}
	}
}

void movenpc(floor& f){
	srand (time(NULL));
    char ch;
    int occ;
    int direction;
    //int count = 0;
    movedead(f);
    for (int i = 1; i < 78; ++i)
    {
        for (int j = 1; j < 24; ++j)
        {
            // check is dead first
            int occupied = f.isoccupied(j, i);
            if (occupied == 2){
                if (f.getmove(j, i)) continue;
                for (int k = 0; k < 8; ++k)
                {
                    f.checkneighbour(j, i, k, ch, occ);
                    if (occ == 1)
                    {
                        f.npcattack(j, i);
                    }
                }
                // check move after
                if (f.getmove(j, i)) continue;
                while (1){
                	int count = 1;
                    direction = rand() % 8;
                    char ch;
                    int occ;
                    f.checkneighbour(j, i, direction, ch, occ);
                    count++;
                    if (count == 50) {
                    	direction = -1;
                    	break;
                    }
                    if ((ch == 'p')&&(occ == 0)) break;
                }
                f.movenpc(j, i, direction);
            }
            else if(occupied == 6){
                for (int k = 0; k < 8; ++k)
                {
                    f.checkneighbour(j, i, k, ch, occ);
                    if (occ == 1)
                    {
                        pc* p = f.getpc();
                        info* in = f.getinfo(j,i);
                        dragontreasure* t = static_cast<dragontreasure*>(in);
                        npc* protector = t->getprotector();
                        f.action += "D";
                        p->beattack(protector, f.action);
                    }
                }
            }
        }
    }
    for (int i = 1; i < 78; ++i)
    {
        for (int j = 1; j < 24; ++j)
            f.changemove(j, i);
    }
}

void moveusedpotion(floor& f){
    for (int i = 1; i < 78; ++i)
    {
        for (int  j= 1; j < 24; ++j)
        {
            int occupied = f.isoccupied(j, i);
            if (occupied == 4)
            {
                info* curinfo = f.getinfo(j, i);
                potion* curpotion = static_cast<potion*>(curinfo);
                int used = curpotion->checkused();
                if(used){
                    f.removeinfo(j, i);
                }
            }
        }
    }
}

void usepotion(string direction, floor& f){
    int row, col;
    f.getpcpos(row, col);
    if (direction == "no"){
        row--;
        f.usepotion(row, col);
    }
    else if (direction == "so"){
        row++;
        f.usepotion(row, col);
    }
    else if (direction == "ea"){
        col++;
        f.usepotion(row, col);
    }
    else if (direction == "we"){
        col--;
        f.usepotion(row, col);
    }
    else if (direction == "ne"){
        col++;
        row--;
        f.usepotion(row, col);
    }
    else if (direction == "nw"){
        row--;
        col--;
        f.usepotion(row, col);
    }
    else if (direction == "sw"){
        row++;
        col--;
        f.usepotion(row, col);
    }
    else if (direction == "se"){
        row++;
        col++;
        f.usepotion(row, col);
    }
}

void attack (string direction, floor& f){
	int row, col;
	f.getpcpos(row, col);
	if (direction == "no"){
		row--;
		f.attacknpc(row, col);
	}
	else if (direction == "so"){
		row++;
		f.attacknpc(row, col);
	}
	else if (direction == "ea"){
		col++;
		f.attacknpc(row, col);
	}
	else if (direction == "we"){
		col--;
		f.attacknpc(row, col);
	}
	else if (direction == "ne"){
		col++;
		row--;
		f.attacknpc(row, col);
	}
	else if (direction == "nw"){
		row--;
		col--;
		f.attacknpc(row, col);
	}
	else if (direction == "sw"){
		row++;
		col--;
		f.attacknpc(row, col);
	}
	else if (direction == "se"){
		row++;
		col++;
		f.attacknpc(row, col);
	}
}

int getscore(floor& f){
    pc* p = f.getpc();
    int score;
    if(p->gettype() == "shade"){
        score = p->getgold();
        score = score * 1.5;
    }else{
        score = p->getgold();
    }
    return score;
}

bool pcdead(floor& f){
	pc* curpc = f.getpc();
	return curpc->isdead();
}

void entercommand(floor &f){
	string command;
	while(cin >> command){
		if(command == "m"){
			string mv;
			cin >> mv;
			try {
				move (mv, f);
				movenpc(f);
			} catch ( int a ) {
				f.clearFloor();
				upstair(f);
			}
		}
		else if(command == "a"){
			string dir;
			cin >> dir;
			attack (dir, f);
			movenpc(f);
		}
		else if(command == "u"){
            string dir;
            cin >> dir;
            usepotion(dir, f);
            moveusedpotion(f);
            movenpc(f);
        }
        bool state = pcdead(f);
        if (!state) break;
        pc* p = f.getpc();
        if(p->gettype() == "troll"){
            p->changehp(-5);
        }
		cout << f;
	}
}


