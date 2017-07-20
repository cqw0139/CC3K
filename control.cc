#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <sstream>
using namespace std;

#include "control.h"

extern bool newmap;

void inittreasure(floor& f){
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
    if (newmap)
        f.getpcpos(row, col);
    pc* newpc = f.getpc();
    delete newpc;
    cout << "Please enter one of s(Shade), d(Drow), v(Vampire), g(Goblin), t(Troll) to choose a race." << endl;
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
        }else{
            cout << "Please enter one of s(Shade), d(Drow), v(Vampire), g(Goblin), t(Troll) to choose a race." << endl;
            continue;
        }
    }
    if (!newmap)
	   randominfo(row ,col, f);
	f.initpc(row, col, newpc);
    f.curFloor = 1;
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
    int pcrow, pccol;
    f.getpcpos(pcrow, pccol);
    int curroom = f.getroom(pcrow, pccol);
    while (1){
        randominfo(row, col, f);
        if (curroom != f.getroom(row, col)) break;
    }
    f.initstair(row, col);
}

void init(floor& f){
    potion* p = new PH;
    p->usedPH = 0;
    p->usedRH = 0;
    p->usedWA = 0;
    p->usedWD = 0;
    p->usedBA = 0;
    p->usedBD = 0;
    merchant* m = new merchant;
    m->hostile = 0;
    f.init();
    f.initBasicMap();
    initpc(f);
    initpotion(f);
    initnpc(f);
    initstair(f);
    inittreasure(f);
    output(f);
    delete p;
    delete m;
}

void upstair(floor& f){
	pc* curpc = f.getpc();
	srand (time(NULL));
	int row, col;
    randominfo(row, col ,f);
	f.setpc(row, col, curpc);
    initstair(f);
	initpotion(f);
	initnpc(f);
	inittreasure(f);
}

bool move(string direction, floor& f){
    bool state = false;
	if (direction == "no"){
		state = f.movechar(0);
	}
	else if(direction == "so"){
		state = f.movechar(1);
	}
	else if(direction == "we"){
		state = f.movechar(2);
	}
	else if(direction == "ea"){
		state = f.movechar(3);
	}
	else if(direction == "nw"){
		state = f.movechar(4);
	}
	else if(direction == "sw"){
		state = f.movechar(5);
	}
	else if(direction == "ne"){
		state = f.movechar(6);
	}
	else if(direction == "se"){
		state = f.movechar(7);
	}
    return state;
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
                int count = 0;
                while (count < 50){
                	count++;
                    direction = rand() % 8;
                    char ch;
                    int occ;
                    f.checkneighbour(j, i, direction, ch, occ);
                    if ((ch == 'p')&&(occ == 0)) break;
                }
                if (count == 50) {
                    direction = -1;
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

void entercommand(floor &f){
	string command;
    int npcmove = 1;
	while(cin >> command){
		if((command == "ea")||(command == "no")||(command == "so")||(command == "we")||
            (command == "nw")||(command == "ne")||(command == "sw")||(command == "se")){
            bool state = move(command, f);
            if(npcmove == 1){
                    movenpc(f);
                }
            if (state){
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
        movedead(f);
        moveusedpotion(f);
        output(f);
        bool state = pcdead(f);
        if (!state){
            cout << "You are dead with score: ";
            cout << getscore(f) << endl;
            printLose();
            cout << "print q to quit or r to restart." << endl;
            while(1){
                cin >> command;
                if(command == "q"){
                    break;
                }else if(command == "r"){
                    floor f;
                    init(f);
                    entercommand(f);
                    break;
                }
            }
        }
        state = iswon(f);
        if (state) {
            cout << "You win with score: ";
            cout << getscore(f) << endl;
            printWin();
        }
	}
}

void output(floor& f){
	pc *curpc= f.getpc();
	cout << f;
	cout << "Race: " << curpc->gettype() << " " << "Gold: " << curpc->getgold();
	cout << "                           floor: " << f.curFloor << endl;
    cout << "HP: " << curpc->gethp() << endl;;
	cout << "Atk: " << curpc->getatk() << endl;
	cout << "Def: " << curpc->getdef() << endl;
    cout << "Action:" << f.action << endl;
    f.resetaction();
}

