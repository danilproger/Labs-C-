//
// Created by danil on 25.11.2019.
//

#include "ConsoleView.h"
#include <iostream>

void ConsoleView::drawMap(const Map &map) {
    std::cout<<"\n\n\n\n\n\n\n\n\n";
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

void ConsoleView::drawAttackMap(const Map &map) {
    std::cout<<"\n\n\n\n\n\n\n\n\n";
    std::cout << "   0 1 2 3 4 5 6 7 8 9" << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << i << ' ' << "|";
        for (size_t j = 0; j < 10; ++j) {
            char c;
            switch(map.getCell(j, i)){
                case EMPTY: c = '_'; break;
                case HIT: c = 'x'; break;
                case MISS: c = 'o'; break;
                default: c = '\0';
            }
            std::cout << c << '|';
        }
        std::cout << std::endl;
    }
}
