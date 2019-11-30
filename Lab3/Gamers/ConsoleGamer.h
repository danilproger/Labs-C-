//
// Created by danil on 25.11.2019.
//

#ifndef LAB3_CONSOLEGAMER_H
#define LAB3_CONSOLEGAMER_H


#include "../Interfaces/IGamer.h"

class ConsoleGamer : public IGamer {
    std::pair<size_t, size_t> attack() override;
    void fillMap(Map &map) override;
};


#endif //LAB3_CONSOLEGAMER_H
