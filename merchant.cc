#include "merchant.h"

int merchant::hostile = 0;

merchant::merchant(): npc(30,70,5,"merchant", 0, hostile){
}

merchant::~merchant(){

}
