#ifndef __potion_h__
#define __potion_h__

#include <iostream>
#include "info.h"
#include <string>

class potion: public info{
protected:
    std::string type;
    int effect;
    int whetherbeused;
public:
    potion(int eff, std::string typ);
    void beused();
    int checkused();
    int geteffect();
    std::string gettype() override;
    ~potion();
};

#endif