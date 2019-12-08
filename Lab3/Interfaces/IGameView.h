//
// Created by danil on 25.11.2019.
//

#ifndef LAB3_IGAMEVIEW_H
#define LAB3_IGAMEVIEW_H

#include "..//Map//Map.h"
#include "../GameController/GameController.h"

class IGameView {
public:
    virtual void drawMap(const Map&) = 0;
    virtual void drawGameState(const Map&, const Map&, const std::pair<size_t, size_t>&) = 0;
    virtual void printMessage(const std::string&) = 0;
};

#endif //LAB3_IGAMEVIEW_H
