
#include "potion.h"
#include <string>
using namespace std;

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