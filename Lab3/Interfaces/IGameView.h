//
// Created by danil on 25.11.2019.
//

#ifndef LAB3_IGAMEVIEW_H
#define LAB3_IGAMEVIEW_H

#include "..//Map//Map.h"
#include "../GameController/GameController.h"

class IGameView {
public:
    virtual void drawMap(const Map &map) = 0;
    virtual void drawAttackMap(const Map &map) = 0;
    virtual void printWinner(const GameMode &mode) = 0;
    virtual void printStep(const Cell &cell) = 0;
    virtual void printScore(const std::pair<size_t, size_t> &gameScore) = 0;
};

#endif //LAB3_IGAMEVIEW_H
