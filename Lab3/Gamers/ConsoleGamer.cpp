//
// Created by danil on 25.11.2019.
//
#include <cmath>
#include "ConsoleGamer.h"
#include "../ConsoleView/ConsoleView.h"

bool canPutShip1(const int &x0, const int &y0, const int &x1, const int &y1, const Map &map) {
    for (int i = std::min(x0, x1) - 1; i < std::max(x0, x1) + 1; i++) {
        for (int j = std::min(y0, y1) - 1; j < std::max(y0, y1) + 1; j++) {
            if (i >= 0 && i < 10 && j >= 0 && j < 10 && map.getCell(i, j) != EMPTY) return false;
        }
    }
    return true;
}

void inputCoords(int &x, int &y, const Map &map, ConsoleView &view) {
    view.printMessage("x: ");
    std::cin >> x;
    view.printMessage("y: ");
    std::cin >> y;
    while (x < 0 || x > 9 || y < 0 || y > 9 || map.getCell(x, y) != EMPTY) {
        view.printMessage("\nWrite correct coords");
        inputCoords(x, y, map, view);
    }
}

void inputShip(int &x0, int &y0, int &x1, int &y1, int shipLong, const Map &map, ConsoleView &view) {
    while (true) {
        view.printMessage("Write x0 y0:");
        inputCoords(x0, y0, map, view);
        if (shipLong == 1) {
            x1 = x0;
            y1 = y0;
        } else {
            view.printMessage("Write x1 y1:");
            inputCoords(x1, y1, map, view);
        }
        if (!(x1 == x0 && abs(y1 - y0) == (shipLong - 1)) && !((y1 == y0) && (abs(x1 - x0) == (shipLong - 1)))) {
            view.printMessage("Write correct coords");
            continue;
        }
        if (canPutShip1(x0, y0, x1, y1, map)) break;

        else {
            view.printMessage("\nWrite correct coords");
        }
    }
}

std::pair<size_t, size_t> ConsoleGamer::attack(const Map &attackMap) {
    int x, y;
    ConsoleView view;
    inputCoords(x, y, attackMap, view);
    return std::make_pair(x, y);
}

void ConsoleGamer::fillMap(Map &map) {
    int x0, y0, x1, y1;
    ConsoleView view;

    view.drawMap(map);

    for (int i = 0; i < TORPEDO_BOATS; ++i) {
        view.printMessage("Input coodrs x y for single boat\n");
        inputShip(x0, y0, x1, y1, 1, map, view);
        map.setCell(x0, y0, SHIP);
    }

    view.drawMap(map);

    for (int i = 0; i < DESTROYERS; ++i) {
        view.printMessage("Input coodrs x0 y0, x1 y1 for double boat\n");

        inputShip(x0, y0, x1, y1, 2, map, view);

        for (int j = 0; j < 2; ++j) {
            if (x0 == x1) {
                int direction = y1 - y0;
                map.setCell(x0, direction > 0 ? y0 + j : y0 - j, SHIP);
            }

            if (y0 == y1) {
                int direction = x1 - x0;
                map.setCell(direction > 0 ? x0 + j : x0 - j, y0, SHIP);
            }
        }
    }

    view.drawMap(map);

    for (int i = 0; i < CRUISERS; ++i) {
        view.printMessage("Input coodrs x0 y0, x1 y1 for triple boat\n");

        inputShip(x0, y0, x1, y1, 3, map, view);

        for (int j = 0; j < 3; ++j) {
            if (x0 == x1) {
                int direction = y1 - y0;
                map.setCell(x0, direction > 0 ? y0 + j : y0 - j, SHIP);
            }

            if (y0 == y1) {
                int direction = x1 - x0;
                map.setCell(direction > 0 ? x0 + j : x0 - j, y0, SHIP);
            }
        }
    }

    view.drawMap(map);

    for (int i = 0; i < BATTLESHIPS; ++i) {
        view.printMessage("Input coodrs x0 y0, x1 y1 for quadruple boat\n");

        inputShip(x0, y0, x1, y1, 4, map, view);

        for (int j = 0; j < 4; ++j) {
            if (x0 == x1) {
                int direction = y1 - y0;
                map.setCell(x0, direction > 0 ? y0 + j : y0 - j, SHIP);
            }

            if (y0 == y1) {
                int direction = x1 - x0;
                map.setCell(direction > 0 ? x0 + j : x0 - j, y0, SHIP);
            }
        }
    }

    view.drawMap(map);
}