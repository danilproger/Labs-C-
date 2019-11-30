//
// Created by danil on 25.11.2019.
//

#ifndef LAB3_GAMECONTROLLER_H
#define LAB3_GAMECONTROLLER_H


#include "../Interfaces/IGameController.h"

enum GameMode {
    IN_PROCESS, WIN_GAMER, WIN_ENEMY
};

class GameController : public IGameController {
public:
    void run(const GamerMode &gamerMode, const size_t &countGames) override;
};


#endif //LAB3_GAMECONTROLLER_H
