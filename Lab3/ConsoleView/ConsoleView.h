//
// Created by danil on 25.11.2019.
//

#ifndef LAB3_CONSOLEVIEW_H
#define LAB3_CONSOLEVIEW_H


#include "../Interfaces/IGameView.h"

class ConsoleView : public IGameView{
public:
    void drawMap(const Map &map) override;
    void drawGameState(const Map &gamer1_attack, const Map &gamer2_attack, const std::pair<size_t, size_t>& gameScore) override;
    void printMessage(const std::string &message) override;
};


#endif //LAB3_CONSOLEVIEW_H
