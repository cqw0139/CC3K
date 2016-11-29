#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "control.h"

int main(int argc, char const *argv[])
{
    floor f;
    init(f);
    entercommand(f);
    cout << "You are dead with score: " << getscore(f) << endl;
    /*floor f;
    ifstream filein;
    filein.open("samplemap.txt");
    setGivenMap(filein, f);
    cout << f;
    filein.close();*/
}
