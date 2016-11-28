#include "dragon.h"

void dragon::biebiemybaby(){
    mybaby->protectdead();
}

void dragon::setbaby(dragontreasure* dt){
    mybaby = dt;
}

dragon::dragon(): npc(150,20,20,"dragon", 0, 1) {}