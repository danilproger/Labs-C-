//
// Created by danil on 25.11.2019.
//

#include <random>
#include "RandomGamer.h"

bool canPutShip(int x0, int y0, int x1, int y1, Map map) {
    if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0 || x0 > 9 || y0 > 9 || x1 > 9 || y1 > 9) return false;
    for (int i = std::min(x0, x1) - 1; i <= std::max(x0, x1) + 1; i++) {
        for (int j = std::min(y0, y1) - 1; j <= std::max(y0, y1) + 1; j++) {
            if (i >= 0 && i < 10 && j >= 0 && j < 10 && map.getCell(i, j) != EMPTY) return false;
        }
    }
    return true;
}

void RandomShip(int amountShips, int longShip, Map &map){
    int dir;
    int x0, y0, x1, y1;

    for (int i = 0; i < amountShips; ++i) {
        while(true){
            x0 = rand()%10;
            y0 = rand()%10;
            dir = rand()%4;

            if (map.getCell(x0, y0) == EMPTY) {
                if (dir == 0 && canPutShip(x0, y0, x0, y0 - longShip, map)) {
                    y1 = y0 - longShip;
                    x1 = x0;
                    break;
                }

                if (dir == 1 && canPutShip(x0, y0, x0, y0 + longShip, map)) {
                    x1 = x0;
                    y1 = y0 + longShip;
                    break;
                }

                if (dir == 2 && canPutShip(x0, y0, x0 - longShip, y0, map)) {
                    y1 = y0;
                    x1 = x0 - longShip;
                    break;
                }

                if (dir == 3 && canPutShip(x0, y0, x0 + longShip, y0, map)) {
                    y1 = y0;
                    x1 = x0 + longShip;
                    break;
                }
            }
        }

        for (int j = 0; j < longShip+1; ++j) {
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
}

std::pair<size_t, size_t> RandomGamer::attack(const Map &attackMap) {
    size_t x, y;
    do {
        x = rand() % 10;
        y = rand() % 10;
    } while (attackMap.getCell(x, y) != EMPTY);
    return std::make_pair(x, y);
}

void RandomGamer::fillMap(Map &map) {
    RandomShip(BATTLESHIPS, 3, map);
    RandomShip(CRUISERS, 2, map);
    RandomShip(DESTROYERS, 1, map);
    RandomShip(TORPEDO_BOATS, 0, map);
}
