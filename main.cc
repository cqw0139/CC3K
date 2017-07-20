#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <string.h>
#include <curses.h>
using namespace std;

#include "bonuscontrol.h"
#include "control.h"
#include "print.h"

bool newmap = 0;

int main(int argc, char const *argv[])
{
    initscr();
    printLogo();
    endwin(); 
    cout << "choose the level that you wanna play" << endl << "n(Normal) or a(Advanced)" << endl;
    string s;
    floor f;
    while(1){
        cin >> s;
        if (s == "n"){
            if (argc > 1){
                ifstream file (argv[argc-1]);
                setGivenMap(file, f);
                newmap = 1;
                initpc(f);
                output(f);
                entercommand(f);
            }
            else{
                init(f);
                entercommand(f);
            }
            break;
        }
        else if (s == "a"){
            while (1){
            initscr();
            if (argc > 1){
                ifstream file (argv[argc-1]);
                setGivenMap(file, f);
                newmap = 1;
                bonusinitpc(f);
                bonusoutput(f);
                command(f);
            }
            else{
                bonusinit(f);
                command(f);
            }
            endwin();
            break;
        }
    }
    else
        cout << "please enter n(Normal) or a(Advanced)" << endl;
    }
    return 0;
}
