//
// Created by danil on 25.11.2019.
//

#include <ctime>
#include <memory>
#include "GameController.h"
#include "../ConsoleView/ConsoleView.h"
#include "../GamerFactory/GamerFactory.h"

void GameController::run(const GamerMode &gamerMode_1, const GamerMode &gamerMode_2, const size_t &countGames) {
    srand(time(0));

    GameMode mode;
    ConsoleView view;
    Map gamer1_map, gamer1_attack_map;
    Map gamer2_map, gamer2_attack_map;
    std::pair<size_t, size_t> gameStep;
    std::pair<size_t, size_t> hitCells = std::make_pair(0, 0);
    std::pair<size_t, size_t> gameScore = std::make_pair(0, 0);
    GamerFactory factory = GamerFactory::getInstance();

    std::unique_ptr<IGamer> gamer_1(factory.create(gamerMode_1));
    std::unique_ptr<IGamer>gamer_2(factory.create(gamerMode_2));

    for (size_t i = 0; i < countGames; i++) {
        mode = IN_PROCESS;
        hitCells = std::make_pair(0, 0);

        gamer1_map.clear();
        gamer2_map.clear();

        gamer1_attack_map.clear();
        gamer2_attack_map.clear();

        gamer_1->fillMap(gamer1_map);
        gamer_2->fillMap(gamer2_map);

        view.drawGameState(gamer1_attack_map, gamer2_attack_map, gameScore);

        while (mode == IN_PROCESS) {
            do {
                view.drawGameState(gamer1_attack_map, gamer2_attack_map, gameScore);
                view.printMessage("Gamer 1, make a step");
                gameStep = gamer_1->attack(gamer1_attack_map);

                if (gamer2_map.getCell(gameStep.first, gameStep.second) == SHIP) {
                    ++hitCells.first;
                    gamer1_attack_map.setCell(gameStep.first, gameStep.second, HIT);
                    gamer2_map.setCell(gameStep.first, gameStep.second, EMPTY);
                } else {
                    gamer1_attack_map.setCell(gameStep.first, gameStep.second, MISS);
                    break;
                }

                if (hitCells.first == 20) {
                    mode = WIN_GAMER_1;
                    ++gameScore.first;
                    break;
                }
            } while (true);

            if (mode != WIN_GAMER_1) {
                do {
                    view.drawGameState(gamer1_attack_map, gamer2_attack_map, gameScore);
                    view.printMessage("Gamer 2, make a step");
                    gameStep = gamer_2->attack(gamer2_attack_map);

                    if (gamer1_map.getCell(gameStep.first, gameStep.second) == SHIP) {
                        ++hitCells.second;
                        gamer2_attack_map.setCell(gameStep.first, gameStep.second, HIT);
                        gamer1_map.setCell(gameStep.first, gameStep.second, EMPTY);
                    } else {
                        gamer2_attack_map.setCell(gameStep.first, gameStep.second, MISS);
                        break;
                    }

                    if (hitCells.second == 20) {
                        mode = WIN_GAMER_2;
                        ++gameScore.second;
                        break;
                    }

                } while (true);
            }
        }

        view.drawGameState(gamer1_attack_map, gamer2_attack_map, gameScore);
        std::string mess = "Gamer " + std::to_string(mode) + " won the lap";
        view.printMessage(mess);
    }

    if(gameScore.first > gameScore.second) view.printMessage("Gamer 1 won the game!!");
    if(gameScore.first < gameScore.second) view.printMessage("Gamer 2 won the game!!");
    if(gameScore.first == gameScore.second) view.printMessage("Draw happened!!!");
}