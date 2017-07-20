#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <curses.h>
#include <sstream>
#include "print.h"
using namespace std;

#include "bonuscontrol.h"

extern bool newmap;

string intos(int i)  // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}

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

void bonusinittreasure(floor& f){
    int row, col;
    int treasuretype;
    treasure* newtreasure;
    int numoftreasure = 0;
    while(1){
        treasuretype = rand() % 8 + 1;
        randominfo(row, col, f);
        if(treasuretype == 1){
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

void bonusinitpotion(floor& f){
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

void bonusinitpc (floor& f){
    srand (time(NULL));
    int row, col;
    // determine the pc race by cilent
    if (newmap)
        f.getpcpos(row, col);
    pc* newpc = f.getpc();
    delete newpc;
    char pctype = printpcinfo();
    if(pctype == 's')
        newpc = new shade();
    else if(pctype == 'd')
        newpc = new drow();
    else if(pctype == 'v')
        newpc = new vampire();
    else if(pctype == 'g')
        newpc = new goblin();
    else if(pctype == 't')
        newpc = new troll();
    else if(pctype == 'a')
        newpc = new saber();
    else if(pctype == 'e')
        newpc = new deathknight();
    if (!newmap)
       randominfo(row ,col, f);
    f.initpc(row, col, newpc);
}

void bonusinitnpc(floor& f){
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

void bonusinitstair(floor& f){
	srand (time(NULL));
    int row, col;
    int pcrow, pccol;
    f.getpcpos(pcrow, pccol);
    int curroom = f.getroom(pcrow, pccol);
    while (1){
        randominfo(row, col, f);
        if (curroom != f.getroom(row, col)) break;
    }
    boss* newboss = new boss;
    newboss->alive = 1;
    f.setboss(newboss);
    npc* newnpc = newboss;
    f.addinfo(row, col, newnpc);
}

void bonusinit(floor& f){
    // init the floor
    f.init();
    // init the basic map
    f.initBasicMap();
    // init pc
    bonusinitpc(f);
    printcontrol();
    // init potion
    bonusinitpotion(f);
    // init npc
    bonusinitnpc(f);
    // init stair
    bonusinitstair(f);
    // init treasure
    bonusinittreasure(f);
    // print the map
    bonusoutput(f);
}

void bonusupstair(floor& f){
	pc* curpc = f.getpc();
	srand (time(NULL));
	int row, col;
	randominfo(row, col ,f);
	f.setpc(row, col, curpc);
    bonusinitstair(f);
	bonusinitpotion(f);
	bonusinitnpc(f);
	bonusinittreasure(f);
}

bool bonusmovepc(int direction, floor& f){
    bool state = false;
	if (direction == 0){
		state = f.movechar(0);
	}
	else if(direction == 1){
		state = f.movechar(1);
	}
	else if(direction == 2){
		state = f.movechar(2);
	}
	else if(direction == 3){
		state = f.movechar(3);
	}
	else if(direction == 4){
		state = f.movechar(4);
	}
	else if(direction == 5){
		state = f.movechar(5);
	}
	else if(direction == 6){
		state = f.movechar(6);
	}
	else if(direction == 7){
		state = f.movechar(7);
	}
    return state;
}

void bonusmovedead(floor& f){
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
                    if(p->check("bloodrage") == 1){
                        int h = 0;
                        h = curnpc->getmaxhp();
                        h = 0.3 * h;
                        if(h > 50){
                            h = 50;
                        }
                        p->changehp(-h);
                        string hp = "";
                        hp = intos(h);
                        f.action = f.action + " BloodRage!!! PC restores " + hp +" HP from dead NPC.";
                    }
                    if(p->check("grow") == 1){
                        int x = 0;
                        x = rand() % 2;
                        int y = 0;
                        y = rand() % 5 + 1;
                        string eff = "";
                        eff = intos(y);
                        if(x == 0){
                            p->changeatk(y);
                            f.action = f.action + " Grow!!! PC adds " + eff +" atk by eating dead NPC.";
                        }else if (x == 1){
                            p->changedef(y);
                            f.action = f.action + " Grow!!! PC adds " + eff +" def by eating dead NPC.";
                        }
                    }
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
                        int check = 0;
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
                                }
                                f.addinfo(r,c,newt2);
                                break;
                            }
                        }
                    }
                }
            }
            else if(occupied == 3){
                info* curinfo = f.getinfo(j, i);
                npc* curnpc = static_cast<npc*>(curinfo);
                bool state = curnpc->isdead();
                if(!state){
                    info* curinfo = f.getinfo(j,i);
                    dragon* d = static_cast<dragon*>(curinfo);
                    d->biebiemybaby();
                    f.removeinfo(j, i);
                    p->addexp(18);
                    if(p->check("bloodrage") == 1){
                        int h = 0;
                        h = curnpc->getmaxhp();
                        h = 0.3 * h;
                        if(h > 50){
                            h = 50;
                        }
                        p->changehp(-h);
                        string hp = "";
                        hp = intos(h);
                        f.action = f.action + " BloodRage!!! PC restores " + hp +" HP from dead NPC.";
                    }
                    if(p->check("grow") == 1){
                        int x = 0;
                        x = rand() % 2;
                        int y = 0;
                        y = rand() % 5 + 1;
                        string eff = "";
                        eff = intos(y);
                        if(x == 0){
                            p->changeatk(y);
                            f.action = f.action + " Grow!!! PC adds " + eff +" atk by eating dead NPC.";
                        }else if (x == 1){
                            p->changedef(y);
                            f.action = f.action + " Grow!!! PC adds " + eff +" def by eating dead NPC.";
                        }
                    }
                }
            }
            else if(occupied == 7){
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
                    if(p->check("bloodrage") == 1){
                        int h = 0;
                        h = curnpc->getmaxhp();
                        h = 0.3 * h;
                        if(h > 50){
                            h = 50;
                        }
                        p->changehp(-h);
                        string hp = "";
                        hp = intos(h);
                        f.action = f.action + " BloodRage!!! PC restores " + hp +" HP from dead NPC.";
                    }
                    if(p->check("grow") == 1){
                        int x = 0;
                        x = rand() % 2;
                        int y = 0;
                        y = rand() % 5 + 1;
                        string eff = "";
                        eff = intos(y);
                        if(x == 0){
                            p->changeatk(y);
                            f.action = f.action + " Grow!!! PC adds " + eff +" atk by eating dead NPC.";
                        }else if (x == 1){
                            p->changedef(y);
                            f.action = f.action + " Grow!!! PC adds " + eff +" def by eating dead NPC.";
                        }
                    }
                }
            }
		}
	}
}

void bonusmovenpc(floor& f){
	srand (time(NULL));
    char ch;
    int occ;
    int direction;
    bonusmovedead(f);
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
                int count = 0;
                while (count < 50){
                    count++;
                    direction = rand() % 8;
                    char ch;
                    int occ;
                    f.checkneighbour(j, i, direction, ch, occ);
                    if ((ch == 'p')&&(occ == 0)) break;
                }
                if (count == 50) direction = -1;
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

void bonusmoveusedpotion(floor& f){
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

void bonusattack (int direction, floor& f){
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

void bonususepotion(int direction, floor& f){
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
	return curpc->isdead(f.action);
}

bool iswon(floor& f){
    return f.curFloor == 6;
}

void setGivenMap(ifstream& map, floor& f){
    f.init();
    string line;
    for (int i = 0; i < 25; ++i)
    {
        getline(map, line);
        for (int j = 0; j < 79; ++j)
        {
            int cur = rand() % 5 + 1;
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
                f.setroom(i, j, cur);
            }
            else if (line[j] == 'E'){
                f.settype(i, j, 'p');
                npc* curnpc = new elf();
                f.addinfo(i, j, curnpc);
                f.setroom(i, j, cur);
            }
            else if (line[j] == '\\'){
                f.settype(i, j, 'p');
                f.initstair(i, j);
                f.setroom(i, j, cur);
            }
            else if (line[j] == 'H'){
                f.settype(i, j, 'p');
                npc* curnpc = new human();
                f.addinfo(i, j, curnpc);
                f.setroom(i, j, cur);
            }
            else if (line[j] == 'W'){
                f.settype(i, j, 'p');
                npc* curnpc = new dwarf();
                f.addinfo(i, j, curnpc);
                f.setroom(i, j, cur);
            }
            else if (line[j] == 'O'){
                f.settype(i, j, 'p');
                npc* curnpc = new orc();
                f.addinfo(i, j, curnpc);
                f.setroom(i, j, cur);
            }   
            else if (line[j] == 'M'){
                f.settype(i, j, 'p');
                npc* curnpc = new merchant();
                f.addinfo(i, j, curnpc);
                f.setroom(i, j, cur);
            }
            else if (line[j] == 'D'){
                f.settype(i, j, 'p');
                npc* curnpc = new dragon();
                f.addinfo(i, j, curnpc);
                f.setroom(i, j, cur);
            }
            else if (line[j] == 'L'){
                f.settype(i, j, 'p');
                npc* curnpc = new halfling();
                f.addinfo(i, j, curnpc);
                f.setroom(i, j, cur);
            }
            else if (line[j] == 'L'){
                f.settype(i, j, 'p');
                npc* curnpc = new halfling();
                f.addinfo(i, j, curnpc);
                f.setroom(i, j, cur);
            }
            else if (line[j] == '0'){
                f.settype(i, j, 'p');
                potion* curpotion = new RH();
                f.addinfo(i, j, curpotion);
                f.setroom(i, j, cur);
            }
            else if (line[j] == '1'){
                f.settype(i, j, 'p');
                potion* curpotion = new BA();
                f.addinfo(i, j, curpotion);
                f.setroom(i, j, cur);
            }
            else if (line[j] == '2'){
                f.settype(i, j, 'p');
                potion* curpotion = new BD();
                f.addinfo(i, j, curpotion);
                f.setroom(i, j, cur);
            }
            else if (line[j] == '3'){
                f.settype(i, j, 'p');
                potion* curpotion = new PH();
                f.addinfo(i, j, curpotion);
                f.setroom(i, j, cur);
            }
            else if (line[j] == '4'){
                f.settype(i, j, 'p');
                potion* curpotion = new WA();
                f.addinfo(i, j, curpotion);
                f.setroom(i, j, cur);
            }
            else if (line[j] == '5'){
                f.settype(i, j, 'p');
                potion* curpotion = new WD();
                f.addinfo(i, j, curpotion);
                f.setroom(i, j, cur);
            }
            else if (line[j] == '6'){
                f.settype(i, j, 'p');
                treasure* curtreasure = new htreasure();
                f.addinfo(i, j, curtreasure);
                f.setroom(i, j, cur);
            }
            else if (line[j] == '7'){
                f.settype(i, j, 'p');
                treasure* curtreasure = new streasure();
                f.addinfo(i, j, curtreasure);
                f.setroom(i, j, cur);
            }
            else if (line[j] == '8'){
                f.settype(i, j, 'p');
                treasure* curtreasure = new mtreasure();
                f.addinfo(i, j, curtreasure);
                f.setroom(i, j, cur);
            }
            else if (line[j] == '9'){
                f.settype(i, j, 'p');
                treasure* curtreasure = new dragontreasure();
                f.addinfo(i, j, curtreasure);
                f.setroom(i, j, cur);
            }
            else{
                f.settype(i, j, 'p');
                f.setroom(i, j, cur);
            }
        }
    }
}

bool command(floor &f){
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
            }
            char type;
            int occ;
            int row;
            int col;
            f.getpcpos(row, col);
            f.checkneighbour(row, col, direction, type, occ);
            refresh();
            if (occ == 2 || occ == 3 || occ == 7){
                bonusattack(direction, f);
                if(npcmove == 1){
                    bonusmovenpc(f);
                }
            }else if(occ == 4){
                bonususepotion(direction, f);
                bonusmoveusedpotion(f);
                if(npcmove == 1){
                    bonusmovenpc(f);
                }
            }
            else {
            bool state = bonusmovepc(direction, f);
            if(npcmove == 1){
                    bonusmovenpc(f);
                }
            if (state){
                f.clearFloor();
                bonusupstair(f);
            }
            }
        }
        else if (cmd == 'i'){
            pc* curpc = f.getpc();
            string type = curpc->gettype();
            int level = curpc->getlevel();
            printinfo(type, level);
        }
        else if(cmd == 'f'){
            if(npcmove == 0){
                        npcmove = 1;
                    }else if(npcmove == 1){
                        npcmove = 0;
                    }
        }
        else if(cmd == 'r'){
            floor f;
            bonusinit(f);
            command(f);
            break;
        }
        else if(cmd == 'q'){
            break;
        }
        else if(cmd == 'c'){
            pc* curpc = f.getpc();
            curpc->cure(f.action);
        }
        pc* p = f.getpc();
        p->naturalrestore();
        p->levelup(f.action);
        bonusmovedead(f);
        bonusmoveusedpotion(f);
        bonusoutput(f);
        bool state = pcdead(f);
        if (!state){
            clear();
            move (5, 10);
            printw("You are dead with score: ");
            printw("%d",getscore(f));
            printw("\n");
            endwin();
            printLose();
            return 1;
        }
        state = iswon(f);
        if (state) {
            printw("You win with score: ");
            printw("%d",getscore(f));
            printw("\n");
            endwin();
            printWin();
            return 0;
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

void clearFloor(floor& f){
    f.clearFloor();
}
