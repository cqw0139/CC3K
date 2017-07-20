#include "dragonT.h"

dragontreasure::dragontreasure(): treasure(6,"T") {}

void dragontreasure::protectdead(){
    wheprotect = 0;
}

int dragontreasure::check(){
    return wheprotect;
}

npc* dragontreasure::getprotector(){
    return protector;
}

void dragontreasure::setprotector(npc* protectd){
    protector = protectd;
}

dragontreasure::~dragontreasure(){
}
