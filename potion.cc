
#include "potion.h"
#include <string>
using namespace std;

int potion::usedRH = 0;
int potion::usedBA = 0;
int potion::usedBD = 0;
int potion::usedPH = 0;
int potion::usedWA = 0;
int potion::usedWD = 0;

potion::potion(int eff, std::string typ):
effect(eff),
type(typ),
whetherbeused(0)
{}

void potion::beused(){
    whetherbeused = 1;
}

int potion::checkused(){
    return whetherbeused;
}

string potion::gettype(){
    return type;
}

int potion::geteffect(){
    return effect;
}


potion::~potion(){
}
