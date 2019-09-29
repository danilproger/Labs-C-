//
// Created by danil on 19.09.2019.
//

#include "tritset.h"

tritset::tritset(size_t size) : size(size) {
    tritset::size = size;
    tritset::capacity = 2 * size / 8 / sizeof(unsigned int) + 1;
    tritset::trits.resize(capacity);
}

tritset::~tritset() {

}

tritset::reference::reference(tritset &tritset, size_t pos) {
    word = &tritset.trits[pos / (sizeof(unsigned int) * 4)];
    trit_pos = pos % (sizeof(unsigned int) * 4);
}

tritset::reference &tritset::reference::operator=(trit x) {
    *word = ((~(static_cast<unsigned int>(3) << trit_pos * 2)) & *word) |
            (static_cast<unsigned int>(x) << (trit_pos * 2));
    return *this;
}

tritset::reference &tritset::reference::operator=(const tritset::reference &x) {
    *word = ((~(static_cast<unsigned int>(3) << trit_pos * 2)) & *word) |
            ((static_cast<unsigned int>(3) & (*(x.word) >> x.trit_pos * 2)) << trit_pos * 2);
    return *this;
}

