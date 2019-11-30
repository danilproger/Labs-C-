//
// Created by danil on 25.11.2019.
//

#ifndef LAB3_CONSOLEVIEW_H
#define LAB3_CONSOLEVIEW_H


#include "../Interfaces/IGameView.h"

class ConsoleView : public IGameView{
public:
    void drawMap(const Map &map) override;
    void drawAttackMap(const Map &map) override;
    void printWinner(const GameMode &mode) override;
    void printStep(const Cell &cell) override;
    void printScore(const std::pair<size_t, size_t> &gameScore) override;
};


#endif //LAB3_CONSOLEVIEW_H
