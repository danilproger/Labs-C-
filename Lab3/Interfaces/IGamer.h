//
// Created by danil on 25.11.2019.
//

#ifndef LAB3_IGAMER_H
#define LAB3_IGAMER_H

#include <iostream>
#include "../Map/Map.h"

enum GamerMode{CONSOLE, RANDOM, OPTIMAL};

class IGamer {
public:
    virtual std::pair<size_t, size_t> attack() = 0;
    virtual void fillMap(Map &map) = 0;
};

#endif //LAB3_IGAMER_H