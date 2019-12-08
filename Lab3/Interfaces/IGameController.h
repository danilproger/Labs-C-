//
// Created by danil on 25.11.2019.
//

#ifndef LAB3_IGAMECONTROLLER_H
#define LAB3_IGAMECONTROLLER_H

#include "../Interfaces/IGamer.h"
class IGameController {
    virtual void run(const GamerMode &gamerMode_1, const GamerMode &gamerMode_2, const size_t &countGames) = 0;
};

#endif //LAB3_IGAMECONTROLLER_H
