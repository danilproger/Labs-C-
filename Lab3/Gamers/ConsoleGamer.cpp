//
// Created by danil on 25.11.2019.
//
#include <cmath>
#include "ConsoleGamer.h"
#include "../GamePreferences.h"
#include "../ConsoleView/ConsoleView.h"

void inputCoords(int &x, int &y, Map &map) {
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    while (x < 0 || x > 9 || y < 0 || y > 9 || map.getCell(x, y) == SHIP) {
        std::cout << "\nWrite correct coords\n";
        inputCoords(x, y, map);
    }
}

std::pair<size_t, size_t> ConsoleGamer::attack() {
    size_t x, y;
    std::cout << "Input coord \nx: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    return std::make_pair(x, y);
}

void ConsoleGamer::fillMap(Map &map) {
    int x0, y0, x1, y1;
    ConsoleView view;

    view.drawMap(map);

    for (int i = 0; i < TORPEDO_BOATS; ++i) {
        std::cout << "Input coodrs x y for single boat\n";
        inputCoords(x0, y0, map);
        map.setCell(x0, y0, SHIP);
    }

    view.drawMap(map);

    for (int i = 0; i < DESTROYERS; ++i) {
        std::cout << "Input coodrs x0 y0, x1 y1 for double boat\nx0 y0:\n";
        inputCoords(x0, y0, map);
        std::cout << "x1 y1:\n";
        inputCoords(x1, y1, map);

        for (int j = 0; j < 2; ++j) {
            if (x0==x1){
                int direction = y1-y0;
                if(direction>0){
                    map.setCell(x0, y0+j, SHIP);
                } else {
                    map.setCell(x0, y0-j, SHIP);
                }
            }

            if(y0==y1){
                int direction = x1-x0;
                if(direction>0){
                    map.setCell(x0+j, y0, SHIP);
                } else {
                    map.setCell(x0-j, y0, SHIP);
                }
            }
        }
    }

    view.drawMap(map);

    for (int i = 0; i < CRUISERS; ++i) {
        std::cout << "Input coodrs x0 y0, x1 y1 for triple boat\nx0 y0:\n";
        inputCoords(x0, y0, map);
        std::cout << "x1 y1:\n";
        inputCoords(x1, y1, map);

        for (int j = 0; j < 3; ++j) {
            if (x0==x1){
                int direction = y1-y0;
                if(direction>0){
                    map.setCell(x0, y0+j, SHIP);
                } else {
                    map.setCell(x0, y0-j, SHIP);
                }
            }

            if(y0==y1){
                int direction = x1-x0;
                if(direction>0){
                    map.setCell(x0+j, y0, SHIP);
                } else {
                    map.setCell(x0-j, y0, SHIP);
                }
            }
        }
    }

    view.drawMap(map);

    for (int i = 0; i < BATTLESHIPS; ++i) {
        std::cout << "Input coodrs x0 y0, x1 y1 for quadruple boat\nx0 y0:\n";
        inputCoords(x0, y0, map);
        std::cout << "x1 y1:\n";
        inputCoords(x1, y1, map);

        for (int j = 0; j < 4; ++j) {
            if (x0==x1){
                int direction = y1-y0;
                if(direction>0){
                    map.setCell(x0, y0+j, SHIP);
                } else {
                    map.setCell(x0, y0-j, SHIP);
                }
            }

            if(y0==y1){
                int direction = x1-x0;
                if(direction>0){
                    map.setCell(x0+j, y0, SHIP);
                } else {
                    map.setCell(x0-j, y0, SHIP);
                }
            }
        }
    }

    view.drawMap(map);
}