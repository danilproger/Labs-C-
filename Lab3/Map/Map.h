//
// Created by danil on 25.11.2019.
//

#ifndef LAB3_MAP_H
#define LAB3_MAP_H

#include "../GamePreferences.h"

enum Cell {
    EMPTY = 0, SHIP, MISS, HIT
};

class Map {
private:
    Cell _map[ROWS][COLUMNS]{};
public:
    const Cell &getCell(const size_t &x, const size_t &y) const;
    void setCell(const size_t &x, const size_t &y, const Cell &new_cell);
    Map();
};


#endif //LAB3_MAP_H
