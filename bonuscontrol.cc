#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <curses.h>
using namespace std;

#include "bonuscontrol.h"



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
//            cout << "There is dragon." << endl;
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
    string pctype;
    pc* newpc;
    cout << "please enter the race you want to play" << endl;
    while(cin >> pctype){
        if(pctype == "s"){
            newpc = new shade;
            break;
        }else if(pctype == "d"){
            newpc = new drow;
            break;
        }else if(pctype == "v"){
            newpc = new vampire;
            break;
        }else if(pctype == "g"){
            newpc = new goblin;
            break;
        }else if(pctype == "t"){
            newpc = new troll;
            break;
        }else if(pctype == "r"){
            newpc = new dragonknight;
            break;
        }else if(pctype == "e"){
            newpc = new deathknight;
            break;
        }else{
            cout << "Please enter one of s, d, v, g, t, r or e to choose a race." << endl;
            continue;
        }
    }
	randominfo(row ,col, f);
	f.initpc(row, col, newpc);
}

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
    boss* newboss = new boss;
    newboss->alive = 1;
//    cout << newboss->gethp() << endl;
    f.setboss(newboss);
    npc* newnpc = newboss;
    f.addinfo(row, col, newnpc);
/*    int r = 0;
    int c = 0;
    f.initstair(row, col);
    char ch;
    int occ;
    for(int i = 0; i < 8; i++){
        f.checkneighbour(row,col,i, ch, occ);
        if((occ == 0)&&(ch == 'p')){
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
            boss* newboss = new boss;
            newboss->alive = 1;
            f.setboss(newboss);
            npc* newnpc = newboss;
            f.addinfo(r, c, newnpc);
            break;
        }
    }*/
}

void init(floor& f){
    f.init();
    f.initBasicMap();
    initpc(f);
    initpotion(f);
    //initdragon(f);
    initnpc(f);
    initstair(f);
    inittreasure(f);
    bonusoutput(f);
}

void upstair(floor& f){
	pc* curpc = f.getpc();
	srand (time(NULL));
	int row, col;
	randominfo(row, col ,f);
	f.initpc(row, col, curpc);
    initstair(f);
	initpotion(f);
	//initdragon(f);
	initnpc(f);
	inittreasure(f);
}

void movepc(int direction, floor& f){
	if (direction == 0){
		f.movechar(0);
	}
	else if(direction == 1){
		f.movechar(1);
	}
	else if(direction == 2){
		f.movechar(2);
	}
	else if(direction == 3){
		f.movechar(3);
	}
	else if(direction == 4){
		f.movechar(4);
	}
	else if(direction == 5){
		f.movechar(5);
	}
	else if(direction == 6){
		f.movechar(6);
	}
	else if(direction == 7){
		f.movechar(7);
	}
}

void movedead(floor& f){
    pc* p = f.getpc();
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
                    p->changegold(g);
					f.removeinfo(j, i);
                    p->addexp(12);
                    string etyp = curnpc->gettype();
                    if(etyp == "merchant"){
                        treasure* newt = new mtreasure;
                        f.addinfo(j,i,newt);
                    }else if(etyp == "human"){
                        treasure* newt1 = new htreasure;
                        f.addinfo(j,i,newt1);
                        treasure* newt2 = new htreasure;
                        char ch;
                        int occ;
                        int k;
                        int check;
                        while(check <= 50){
                            check++;
                            k = rand() % 4;
                            f.checkneighbour(j, i, k, ch, occ);
                            if((ch == 'p')&&(occ == 0)){
                                int r = 0;
                                int c = 0;
                                if(k == 0) {
                                    r = j - 1;
                                    c = i;
                                }else if(k == 1){
                                    r = j + 1;
                                    c = i;
                                }else if(k == 2){
                                    r = j;
                                    c = i - 1;
                                }else if(k == 3){
                                    r = j;
                                    c = i + 1;
                                }else if(k == 4){
                                    r = j - 1;
                                    c = i - 1;
                                }else if(k == 5){
                                    r = j + 1;
                                    c = i - 1;
                                }else if(k == 6){
                                    r = j - 1;
                                    c = i + 1;
                                }else if(k == 7){
                                    r = j + 1;
                                    c = i + 1;
                                }
                                f.addinfo(r,c,newt2);
                                break;
                            }
                        }
                    }
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
                    p->addexp(18);
                }
            }else if(occupied == 7){
                info* curinfo = f.getinfo(j, i);
                npc* curnpc = static_cast<npc*>(curinfo);
                bool state = curnpc->isdead();
                if(!state){
                    int g = curnpc->getgold();
                    info* curinfo = f.getinfo(j,i);
                    boss* b = static_cast<boss*>(curinfo);
                    b->alive = 0;
                    p->changegold(g);
                    f.removeinfo(j, i);
                    p->addexp(36 * f.curFloor);
                    f.initstair(j, i);
                    f.action += " The floor boss is killed, and the floor stair appears.";
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
                        info* in = f.getinfo(j,i);
                        dragontreasure* t = static_cast<dragontreasure*>(in);
                        int check = t->check();
                        if(check == 1){
                            pc* p = f.getpc();
                            npc* protector = t->getprotector();
                            f.action += "D";
                            p->beattack(protector, f.action);
                        }
                    }
                }
            }else if(occupied == 7){
                for (int k = 0; k < 8; ++k)
                {
                    f.checkneighbour(j, i, k, ch, occ);
                    if (occ == 1)
                    {
                        f.npcattack(j, i);
                    }
                }
            }
        }
    }
    for (int i = 1; i < 78; ++i)
    {
        for (int j = 1; j < 24; ++j)
            f.resetmove(j, i);
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

void attack (int direction, floor& f){
    int row, col;
    f.getpcpos(row, col);
    if (direction == 0){
        row--;
        f.attacknpc(row, col);
    }
    else if (direction == 1){
        row++;
        f.attacknpc(row, col);
    }
    else if (direction == 3){
        col++;
        f.attacknpc(row, col);
    }
    else if (direction == 2){
        col--;
        f.attacknpc(row, col);
    }
    else if (direction == 6){
        col++;
        row--;
        f.attacknpc(row, col);
    }
    else if (direction == 4){
        row--;
        col--;
        f.attacknpc(row, col);
    }
    else if (direction == 5){
        row++;
        col--;
        f.attacknpc(row, col);
    }
    else if (direction == 7){
        row++;
        col++;
        f.attacknpc(row, col);
    }
}

void usepotion(int direction, floor& f){
    int row, col;
    f.getpcpos(row, col);
    if (direction == 0){
        row--;
        f.usepotion(row, col);
    }
    else if (direction == 1){
        row++;
        f.usepotion(row, col);
    }
    else if (direction == 3){
        col++;
        f.usepotion(row, col);
    }
    else if (direction == 2){
        col--;
        f.usepotion(row, col);
    }
    else if (direction == 4){
        col++;
        row--;
        f.usepotion(row, col);
    }
    else if (direction == 5){
        row--;
        col--;
        f.usepotion(row, col);
    }
    else if (direction == 6){
        row++;
        col--;
        f.usepotion(row, col);
    }
    else if (direction == 7){
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
    if(p->check("shadenative") == 1){
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

/*void entercommand(floor &f){
	string command;
    int npcmove = 1;
	while(cin >> command){
		if(command == "m"){
			string mv;
			cin >> mv;
			try {
				move (mv, f);
                if(npcmove == 1){
                    movenpc(f);
                }
			} catch ( int a ) {
				f.clearFloor();
				upstair(f);
			}
		}
		else if(command == "a"){
			string dir;
			cin >> dir;
			attack (dir, f);
            if(npcmove == 1){
                movenpc(f);
            }
		}
		else if(command == "u"){
            string dir;
            cin >> dir;
            usepotion(dir, f);
            moveusedpotion(f);
            if(npcmove == 1){
                movenpc(f);
            }
        }else if(command == "f"){
            if(npcmove == 0){
                npcmove = 1;
            }else if(npcmove == 1){
                npcmove = 0;
            }
        }else if(command == "r"){
            floor f;
            init(f);
            entercommand(f);
            break;
        }else if(command == "q"){
            break;
        }
        pc* p = f.getpc();
        p->naturalrestore();
        p->levelup(f.action);
        output(f);
        bool state = pcdead(f);
        if (!state){
            cout << "You are dead with score: " << getscore(f) << endl;
            break;
        }
	}
}*/

void setGivenMap(ifstream& map, floor& f){
	f.init();
	string line;
	for (int i = 0; i < 25; ++i)
	{
		getline(map, line);
		//cout << line << endl;
		for (int j = 0; j < 79; ++j)
		{
			if (line[j] == '|')
				f.settype(i, j, 'v');
			else if (line[j] == '-')
				f.settype(i, j, 'h');
			else if (line[j] == ' ') 
				f.settype(i, j, 'b');
			else if (line[j] == '#') 
				f.settype(i, j, 'c');
			else if (line[j] == '+')
				f.settype(i, j, 'd');
			else if (line[j] == '@'){
				f.settype(i, j, 'p');
				pc* curpc = new pc();
				f.initpc(i, j, curpc);
			}
			else if (line[j] == 'E'){
				f.settype(i, j, 'p');
				npc* curnpc = new elf();
				f.addinfo(i, j, curnpc);
			}
			else if (line[j] == 'H'){
				f.settype(i, j, 'p');
				npc* curnpc = new human();
				f.addinfo(i, j, curnpc);
			}
			else if (line[j] == 'W'){
				f.settype(i, j, 'p');
				npc* curnpc = new dwarf();
				f.addinfo(i, j, curnpc);
			}
			else if (line[j] == 'O'){
				f.settype(i, j, 'p');
				npc* curnpc = new orc();
				f.addinfo(i, j, curnpc);
			}	
			else if (line[j] == 'M'){
				f.settype(i, j, 'p');
				npc* curnpc = new merchant();
				f.addinfo(i, j, curnpc);
			}
			else if (line[j] == 'D'){
				f.settype(i, j, 'p');
				npc* curnpc = new dragon();
				f.addinfo(i, j, curnpc);
			}
			else if (line[j] == 'L'){
				f.settype(i, j, 'p');
				npc* curnpc = new halfling();
				f.addinfo(i, j, curnpc);
			}
			else if (line[j] == 'L'){
				f.settype(i, j, 'p');
				npc* curnpc = new halfling();
				f.addinfo(i, j, curnpc);
			}
			else if (line[j] == '0'){
				f.settype(i, j, 'p');
				potion* curpotion = new RH();
				f.addinfo(i, j, curpotion);
			}
			else if (line[j] == '1'){
				f.settype(i, j, 'p');
				potion* curpotion = new BA();
				f.addinfo(i, j, curpotion);
			}
			else if (line[j] == '2'){
				f.settype(i, j, 'p');
				potion* curpotion = new BD();
				f.addinfo(i, j, curpotion);
			}
			else if (line[j] == '3'){
				f.settype(i, j, 'p');
				potion* curpotion = new PH();
				f.addinfo(i, j, curpotion);
			}
			else if (line[j] == '4'){
				f.settype(i, j, 'p');
				potion* curpotion = new WA();
				f.addinfo(i, j, curpotion);
			}
			else if (line[j] == '5'){
				f.settype(i, j, 'p');
				potion* curpotion = new WD();
				f.addinfo(i, j, curpotion);
			}
			else if (line[j] == '6'){
				f.settype(i, j, 'p');
				treasure* curtreasure = new htreasure();
				f.addinfo(i, j, curtreasure);
			}
			else if (line[j] == '7'){
				f.settype(i, j, 'p');
				treasure* curtreasure = new streasure();
				f.addinfo(i, j, curtreasure);
			}
			else if (line[j] == '8'){
				f.settype(i, j, 'p');
				treasure* curtreasure = new mtreasure();
				f.addinfo(i, j, curtreasure);
			}
			else if (line[j] == '9'){
				f.settype(i, j, 'p');
				treasure* curtreasure = new dragontreasure();
				f.addinfo(i, j, curtreasure);
			}
			else
				f.settype(i, j, 'p');
		}
	}
}

void output(floor& f){
	pc *curpc= f.getpc();
	cout << f;
	cout << "Race: " << curpc->gettype() << " " << "Gold: " << curpc->getgold();
	cout << " Level: " << curpc->getlevel() << "    floor: " << f.curFloor << endl;
    cout << "HP: " << curpc->gethp() <<"   MP: " << curpc->getmp();
    cout << "   Exp: " << curpc->getexp() << "/100" << endl;
	cout << "Atk: " << curpc->getatk() << endl;
	cout << "Def: " << curpc->getdef() << endl;
    cout << "Action:" << f.action << endl;
    f.resetaction();
}

void command(floor &f){
	char cmd;
    int npcmove = 1;
	while(1){
		cmd = getch();
		if(cmd == 'w' || cmd == 'a' || cmd == 's' || cmd == 'd'){
			int direction = 0;
			switch(cmd){
				case 'w':{
					direction = 0;
					break;
				}
				case 's':{
					direction = 1;
					break;
				}
				case 'a':{
					direction = 2;
					break;
				}
				case 'd':{
					direction = 3;
					break;
				}
                case 'f':{
                    if(npcmove == 0){
                        npcmove = 1;
                    }else if(npcmove == 1){
                        npcmove = 0;
                    }
                }
                case 'r':{
                    floor f;
                    init(f);
                    command(f);
                    break;
                }
			}
			char type;
			int occ;
			int row;
			int col;
			f.getpcpos(row, col);
			f.checkneighbour(row, col, direction, type, occ);
			refresh();
			if (occ == 2 || occ == 3 || occ == 7){
				attack(direction, f);
                if(npcmove == 1){
                    movenpc(f);
                }
            }else if(occ == 4){
                usepotion(direction, f);
                moveusedpotion(f);
                if(npcmove == 1){
                    movenpc(f);
                }
            }
			else {
				try {
					movepc(direction, f);
                    if(npcmove == 1){
                        movenpc(f);
                    }
				}
				catch( int a ){
					f.clearFloor();
					upstair(f);
				}
			}
		}
        pc* p = f.getpc();
        p->naturalrestore();
        p->levelup(f.action);
		bonusoutput(f);
        bool state = pcdead(f);
        if (!state){
            clear();
            refresh();
            printw("You are dead with score: ");
            printw("%d",getscore(f));
            printw("\n");
            break;
        }
	}
}


void printMap(floor &f){
	initscr();
	for (int i = 0; i < 25; ++i)
	{
		move(i, 0);
		for (int j = 0; j < 79; ++j)
		{
			if (f.isoccupied(i, j)){
				char c = f.getchartype(i, j);
				switch (c){
					case 'p':{
						printw("%c", '@');
						break;
					}
					case 'L':{
						printw("%c", 'L');
						break;
					}
					case 'd':{
						printw("%c", 'W');
						break;
					}
					case 'H':{
						printw("%c", 'H');
						break;
					}
					case 'e':{
						printw("%c", 'E');
						break;
					}
					case 'o':{
						printw("%c", 'O');
						break;
					}
					case 'm':{
						printw("%c", 'M');
						break;
					}
					case '\\':{
						printw("%c", '\\');
						break;
					}
					case 'T':{
						printw("%c", 'G');
						break;
					}
					case 'D':{
						printw("%c", 'D');
						break;
					}
					case 'P':{
						printw("%c", 'P');
						break;
					}
					case 'G':{
                        printw("%c", 'G');
                        break;
                    }
                    case 'B':{
                    	printw("%c", 'B');
                    	break;
                    }

				}
			}
			else{
				char c = f.gettype(i, j);
				switch (c){
					case 'h':{
						printw("%c", '-');
						break;
					}
					case 'd':{
						printw("%c", '+');
						break;
					}	
					case 'c':{
						printw("%c", '#');
						break;
					}
					case 'b':{
						printw("%c", ' ');
						break;
					}
					case 'p':{
						printw("%c", '.');
						break;
					}
					case 'v':{
						printw("%c", '|');
						break;
					}
				}
			}
		}
		//printw("%c", '\n');
		refresh();
	}
}

void bonusoutput(floor& f){
	clear();
	pc *curpc= f.getpc();
	printMap(f);
	move(25, 0);
	printw("%s", "Race: ");
	printw("%s", curpc->gettype().c_str());
	printw("%s", " Gold: ");
	printw("%d", curpc->getgold());
    printw("%s", " Level: ");
    printw("%d", curpc->getlevel());
	printw("%s", "   Floor: ");
	printw("%d", f.curFloor);
	refresh();
	move(26, 0);
	printw("%s", "HP: ");
	printw("%d", curpc->gethp());
    printw("%s", "   MP: ");
    printw("%d", curpc->getmp());
    printw("%s", "   Exp: ");
    printw("%d", curpc->getexp());
    printw("/100");
	move(27, 0);
	printw("%s", "Atk: ");
	printw("%d", curpc->getatk());
	move(28, 0);
	printw("%s", "Def: ");
	printw("%d", curpc->getdef());
	move(29, 0);
	printw("%s", "Action:");
	printw("%s", f.action.c_str());
	move(30, 0);
    f.resetaction();
}