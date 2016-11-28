#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "control.h"

int main(int argc, char const *argv[])
{
    floor f;
    init(f);
    entercommand(f);
    cout << "You are dead with score: " << getscore(f) << endl;
}
