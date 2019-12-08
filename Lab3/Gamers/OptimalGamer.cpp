//
// Created by danil on 25.11.2019.
//

#include "OptimalGamer.h"

bool canPutShip1(int x0, int y0, int x1, int y1, Map map) {
    if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0 || x0 > 9 || y0 > 9 || x1 > 9 || y1 > 9) return false;
    for (int i = std::min(x0, x1) - 1; i <= std::max(x0, x1) + 1; i++) {
        for (int j = std::min(y0, y1) - 1; j <= std::max(y0, y1) + 1; j++) {
            if (i >= 0 && i < 10 && j >= 0 && j < 10 && map.getCell(i, j) != EMPTY) return false;
        }
    }
    return true;
}

void putAngle(Map &map, int *angleShips, int longShip) {
    int angle;
    int x0, y0, x1, y1;
    int dir = rand() % 2 + 1;

    while (true) {
        angle = rand() % 4;
        if (angleShips[angle] == 0) break;
    }
    angleShips[angle] = 1;

    switch (angle) {
        case 0:
            x0 = 0;
            y0 = 0;
            if (dir == 1) {
                x1 = x0 + longShip;
                y1 = 0;
            } else {
                x1 = 0;
                y1 = y0 + longShip;
            }
            break;
        case 1:
            x0 = 9;
            y0 = 0;
            if (dir == 1) {
                x1 = x0 - longShip;
                y1 = 0;
            } else {
                x1 = 9;
                y1 = y0 + longShip;
            }
            break;
        case 2:
            x0 = 9;
            y0 = 9;
            if (dir == 1) {
                x1 = x0 - longShip;
                y1 = 9;
            } else {
                x1 = 9;
                y1 = 6;
            }
            break;
        case 3:
            x0 = 0;
            y0 = 9;
            if (dir == 1) {
                x1 = x0 + longShip;
                y1 = 9;
            } else {
                x1 = 0;
                y1 = y0 - longShip;
            }
            break;
        default:
            break;
    }

    for (int j = 0; j < longShip + 1; ++j) {
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

void putSides(Map &map) {
    int x0, y0, x1, y1;
    int count = 0;

    x0 = x1 = 0;
    for (y0 = 0; y0 < 9; y0++) {
        y1 = y0 + 1;
        if (canPutShip1(x0, y0, x1, y1, map)) {
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
            count++;
            break;

        }
    }

    y0 = y1 = 9;
    for (x0 = 0; x0 < 9; x0++) {
        x1 = x0 + 1;
        if (canPutShip1(x0, y0, x1, y1, map)) {
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
            count++;
            break;

        }
    }

    if (count < 2) {
        x0 = x1 = 9;
        for (y0 = 9; y0 > 0; y0--) {
            y1 = y0 - 1;
            if (canPutShip1(x0, y0, x1, y1, map)) {
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
                count++;
                break;
            }
        }
    }

    if (count < 2) {
        y0 = y1 = 0;
        for (x0 = 9; x0 > 0; x0--) {
            x1 = x0 - 1;
            if (canPutShip1(x0, y0, x1, y1, map)) {
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
                break;
            }
        }
    }
}

void putSingles(Map &map) {
    int x0, y0;
    for (int i = 0; i < 4; i++) {
        while (true) {
            x0 = rand() % 10;
            y0 = rand() % 10;
            if (map.getCell(x0, y0) == EMPTY && canPutShip1(x0, y0, x0, y0, map)) break;
        }
        map.setCell(x0, y0, SHIP);
    }
}

std::pair<size_t, size_t> OptimalGamer::attack(const Map &attackMap) {
    size_t x, y, step;
    while (true) {
        x = rand() % 10;
        y = rand() % 10;

        if (attackMap.getCell(x, y) == EMPTY) {
            return std::make_pair(x, y);
        }

        if (attackMap.getCell(x, y) == HIT) {
            if (((x > 1) && attackMap.getCell(x - 1, y) == HIT) || ((x < 8) && attackMap.getCell(x + 1, y) == HIT)) {
                if ((x > 2) && attackMap.getCell(x - 2, y) == EMPTY) {
                    return std::make_pair(x - 2, y);
                }

                if ((x < 7) && attackMap.getCell(x + 2, y) == EMPTY) {
                    return std::make_pair(x + 2, y);
                }

                continue;
            }

            if (((y > 1) && attackMap.getCell(x, y - 1) == HIT) || ((y < 8) && attackMap.getCell(x, y + 1) == HIT)) {
                if ((y > 2) && attackMap.getCell(x, y - 2) == EMPTY) {
                    return std::make_pair(x, y - 2);
                }

                if ((y < 7) && attackMap.getCell(x, y + 2) == EMPTY) {
                    return std::make_pair(x, y + 2);
                } else {
                    while (true) {

                        step = rand() % (10 - x);
                        for (size_t i = 0; i < step; i++) {
                            step -= i;
                            if (x < 9 - step && attackMap.getCell(x + step, y) == EMPTY)
                                return std::make_pair(x + step, y);

                            if (y < 9 - step && attackMap.getCell(x, y + step) == EMPTY)
                                return std::make_pair(x, y + step);

                            if (x > step && attackMap.getCell(x - step, y) == EMPTY)
                                return std::make_pair(x - step, y);

                            if (y > step && attackMap.getCell(x, y + step) == EMPTY)
                                return std::make_pair(x, y - step);

                            if (x < 9 - step && y < 9 - step && attackMap.getCell(x + step, y + step) == EMPTY)
                                return std::make_pair(x + step, y + step);

                            if (y < 9 - step && x > step && attackMap.getCell(x, y + step) == EMPTY)
                                return std::make_pair(x - step, y + step);

                            if (x > step && y > step && attackMap.getCell(x - step, y) == EMPTY)
                                return std::make_pair(x - step, y - step);

                            if (y > step && x < 9 - step && attackMap.getCell(x, y + step) == EMPTY)
                                return std::make_pair(x + step, y - step);

                        }
                        break;
                    }
                }
            }
        }
    }

}

void OptimalGamer::fillMap(Map &map) {
    int angleShips[4] = {0};

    putAngle(map, angleShips, 3);
    putAngle(map, angleShips, 2);
    putAngle(map, angleShips, 2);
    putAngle(map, angleShips, 1);

    putSides(map);

    putSingles(map);
}
