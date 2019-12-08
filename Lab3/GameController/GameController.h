//
// Created by danil on 25.11.2019.
//

#ifndef LAB3_GAMECONTROLLER_H
#define LAB3_GAMECONTROLLER_H


#include "../Interfaces/IGameController.h"

enum GameMode {
    IN_PROCESS, WIN_GAMER_1, WIN_GAMER_2
};

class GameController : public IGameController {
public:
    void run(const GamerMode &gamerMode_1, const GamerMode &gamerMode_2, const size_t &countGames) override;
};


#endif //LAB3_GAMECONTROLLER_H
