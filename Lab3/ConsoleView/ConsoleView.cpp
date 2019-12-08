//
// Created by danil on 25.11.2019.
//

#include "ConsoleView.h"
#include <iostream>
#include <conio.h>

void ConsoleView::drawMap(const Map &map) {
    system("CLS");
    std::cout << "   0 1 2 3 4 5 6 7 8 9" << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << i << ' ' << "|";
        for (size_t j = 0; j < 10; ++j) {
            char c = map.getCell(j, i) == EMPTY ? '_' : '*';
            std::cout << c << '|';
        }
        std::cout << std::endl;
    }
}

void ConsoleView::drawGameState(const Map &gamer1_attack, const Map &gamer2_attack, const std::pair<size_t, size_t>& gameScore) {
    system("CLS");

    std::cout << "                 Game score - "<<gameScore.first<<':'<<gameScore.second<<std::endl;
    std::cout << "   gamer 1 attack map:       gamer 2 attack map:"<<std::endl;
    std::cout << "   0 1 2 3 4 5 6 7 8 9       0 1 2 3 4 5 6 7 8 9" << std::endl;

    for (size_t i = 0; i < 10; ++i) {
        std::cout << i << ' ' << "|";
        for (size_t j = 0; j < 21; ++j) {
            if (j < 10) {
                char c;
                switch (gamer1_attack.getCell(j, i)) {
                    case EMPTY:
                        c = '_';
                        break;
                    case HIT:
                        c = 'x';
                        break;
                    case MISS:
                        c = 'o';
                        break;
                    default:
                        c = '_';
                }
                std::cout << c << '|';
            }

            if (j==10) std::cout<<"   "<<i<<' '<<'|';

            if(j>10){
                char c;
                switch (gamer2_attack.getCell(j, i)) {
                    case EMPTY:
                        c = '_';
                        break;
                    case HIT:
                        c = 'x';
                        break;
                    case MISS:
                        c = 'o';
                        break;
                    default:
                        c = '_';
                }
                std::cout << c << '|';
            }
        }
        std::cout << std::endl;
    }
}

void ConsoleView::printMessage(const std::string &message) {
    std::cout<<std::endl<<message<<std::endl;
}
