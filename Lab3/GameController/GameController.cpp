//
// Created by danil on 25.11.2019.
//

#include "GameController.h"
#include "../Gamers/ConsoleGamer.h"
#include "../Gamers/RandomGamer.h"
#include "../Gamers/OptimalGamer.h"
#include "../ConsoleView/ConsoleView.h"

bool gameOver(const Map &map) {
    bool gameOver = true;
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            if (map.getCell(j, i) != EMPTY) gameOver = false;
        }
    }
    return gameOver;
}

void GameController::run(const GamerMode &gamerMode, const size_t &countGames) {
    GameMode mode;
    ConsoleView view;
    Map gamer_map, gamer_attack_map;
    Map enemy_map, enemy_attack_map;
    IGamer *gamer = new ConsoleGamer;
    IGamer *enemy = nullptr;
    std::pair<size_t, size_t> gameStep;
    std::pair<size_t, size_t> gameScore = std::make_pair(0, 0);

    switch (gamerMode) {
        case CONSOLE:
            enemy = new ConsoleGamer;
            break;

        case RANDOM:
            enemy = new RandomGamer;
            break;

        case OPTIMAL:
            enemy = new OptimalGamer;
            break;
        default:
            enemy = nullptr;
    }

    for (size_t i = 0; i < countGames; i++) {
        mode = IN_PROCESS;
        gamer->fillMap(gamer_map);
        enemy->fillMap(enemy_map);

        while (true) {
            view.drawAttackMap(gamer_attack_map);
            gameStep = gamer->attack();

            if (enemy_map.getCell(gameStep.first, gameStep.second) == SHIP) {
                gamer_attack_map.setCell(gameStep.first, gameStep.second, HIT);
                enemy_map.setCell(gameStep.first, gameStep.second, EMPTY);
            } else {
                gamer_attack_map.setCell(gameStep.first, gameStep.second, MISS);
            }

            if (gameOver(enemy_map)) {
                mode = WIN_GAMER;
                ++gameScore.first;
                break;
            }

            view.drawAttackMap(enemy_attack_map);
            gameStep = enemy->attack();

            if (gamer_map.getCell(gameStep.first, gameStep.second) == SHIP) {
                enemy_attack_map.setCell(gameStep.first, gameStep.second, HIT);
                gamer_map.setCell(gameStep.first, gameStep.second, EMPTY);
            } else {
                enemy_attack_map.setCell(gameStep.first, gameStep.second, MISS);
            }

            if (gameOver(gamer_map)) {
                mode = WIN_ENEMY;
                ++gameScore.second;
                break;
            }
        }
        view.printWinner(mode);
    }

}