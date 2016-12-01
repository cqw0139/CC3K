//
//  skill.hpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-30.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#ifndef skill_h
#define skill_h

#include <iostream>
#include <string>

class skill{
private:
    std::string name;
    std::string description;
public:
    skill(std::string n, std::string d);
    std::string getname();
    ~skill();
};

#endif 
