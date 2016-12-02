#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "bonuscontrol.h"



int main(int argc, char const *argv[])
{
    //char a[100];
    floor f;
    init(f);
    //getstr(a);
    //endwin();
    command(f);
    //cout << "You are dead with score: " << getscore(f) << endl;
    /*floor f;
    ifstream filein;
    filein.open("samplemap.txt");
    setGivenMap(filein, f);
    cout << f;
    filein.close();*/
}