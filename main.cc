#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <string.h>
#include <curses.h>
using namespace std;

#include "bonuscontrol.h"
#include "print.h"



int main(int argc, char const *argv[])
{
    initscr();
    printLogo();
    //char a[100];
    floor f;
    //getstr(a);
    //endwin();
    while (1){
        init(f);
        bool state = command(f);
        if (state) {
            move(6, 10);
            printw("%s", "print q to quit or r to restart.");
            refresh();
            char c;
            c = getch();
            if (c == 'q') break;
            else {
                clear();
                clearFloor(f);
            }
        }
    }
    endwin();
    return 0;
    //cout << "You are dead with score: " << getscore(f) << endl;
    /*floor f;
     ifstream filein;
     filein.open("samplemap.txt");
     setGivenMap(filein, f);
     cout << f;
     filein.close();*/
}
