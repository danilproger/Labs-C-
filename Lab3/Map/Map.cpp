//
// Created by danil on 25.11.2019.
//

#include "Map.h"

Map::Map() {
    for (auto & i : _map) {
        for (auto & j : i) {
            j = EMPTY;
        }
    }
}

const Cell &Map::getCell(const size_t &x, const size_t &y) const{
    return _map[y][x];
}

void Map::setCell(const size_t &x, const size_t &y, const Cell &new_cell) {
    _map[y][x] = new_cell;
}
