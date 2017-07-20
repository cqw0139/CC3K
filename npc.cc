#include "npc.h"
#include <string>
using namespace std;

npc::npc(int h, int a, int d, string t, int g, int host):
hp(h),
maxhp(h),
atk(a),
def(d),
type(t),
gold(g),
hostile(host)
{}

npc::npc(int h, int a, int d, string t, int host):
hp(h),
maxhp(h),
atk(a),
def(d),
type(t),
hostile(host){
    int g = rand() % 2 + 1;
    gold = g;
}

void npc::sethostile(int h){
    hostile = h;
}

void npc::setrow(int r){
    row = r;
}
void npc::setcol(int c){
    col = c;
}

void npc::setgold(int g){
    gold = g;
}

int npc::gethostile() const{
    return hostile;
}

int npc::getgold() const{
    return gold;
}

int npc::getrow() const{
    return row;
}

int npc::getcol() const{
    return col;
}

bool npc::isdead() {
    return gethp() > 0;
}

void npc::changehp(int damage){
    hp = hp - damage;
    if(hp < 0){
        hp = 0;
    }
}

void npc::changeatk(int effect){
    atk = atk + effect;
    if(atk < 0){
        hp = 0;
    }
}

void npc::changedef(int effect){
    def = def + effect;
    if(def < 0){
        def = 0;
    }
}

int npc::gethp() const{
    return hp;
}

int npc::getmaxhp() const{
    return maxhp;
}

int npc::getatk() const{
    return atk;
}

int npc::getdef() const{
    return def;
}

string npc::gettype(){
    return type;
}

npc::~npc(){
}
