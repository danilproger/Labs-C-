//
// Created by danil on 19.09.2019.
//

#include <iostream>
#include "tritset.h"

constexpr size_t allocated_memory(size_t size) {
    if (size < 16) return 1;
    if (!(2 * size / 8 % sizeof(uint))) return 2 * size / 8 / sizeof(uint);
    return 2 * size / 8 / sizeof(uint) + 1;
}

tritset::tritset(size_t size) {
    tritset::size = size;
    tritset::capacity = allocated_memory(size);
    tritset::trits = new uint[capacity];
    std::fill(trits, trits + capacity, 0);
}

void tritset::realloc(size_t new_size) {
    size_t new_capacity = allocated_memory(new_size);
    uint *new_trits = new uint[new_capacity];
    std::fill(new_trits, new_trits + new_capacity, 0);
    for (int i = 0; i < std::min(capacity, new_capacity); ++i) {
        new_trits[i] = trits[i];
    }
    delete[]trits;
    size = new_size;
    capacity = new_capacity;
    trits = new_trits;
}

tritset::~tritset() {
    delete[]trits;
}

size_t tritset::getSize() const {
    return size;
}

size_t tritset::getCapacity() const {
    return capacity;
}

tritset::reference::reference(tritset &tritset, size_t pos) {
    trits = &tritset;
    trit_pos = pos;
}

tritset::reference tritset::operator[](size_t key) {
    return reference(*this, key);
}

tritset::reference &tritset::reference::operator=(trit x) {
    if (trit_pos >= trits->size) {
        (*trits).realloc(trit_pos);
    }
    *(trits->trits + word_position(trit_pos)) =
            ((~(static_cast<uint>(3) << trit_position(trit_pos) * 2)) & *(trits->trits + word_position(trit_pos))) |
            (static_cast<uint>(x) << (trit_position(trit_pos) * 2));
    return *this;
}

tritset::reference &tritset::reference::operator=(const tritset::reference &x) {
    *(trits + word_position(trit_pos)) =
            ((~(static_cast<uint>(3) << trit_pos * 2)) & *(trits + word_position(trit_pos))) |
            ((static_cast<uint>(3) & (*(x.trits->trits + word_position(trit_pos)) >> x.trit_pos * 2))
                    << trit_position(trit_pos) * 2);
    return *this;
}

tritset operator&(tritset left, tritset right) {
    size_t size = std::max(left.getSize(), right.getSize());
    tritset tritset(size);
    for (int i = 0; i < size; i++) {
        tritset[i] = left[i] & right[i];
    }
    return tritset;
}

tritset operator|(tritset left, tritset right) {
    size_t size = std::max(left.getSize(), right.getSize());
    tritset tritset(size);
    for (int i = 0; i < size; i++) {
        tritset[i] = left[i] | right[i];
    }
    return tritset;
}

tritset operator~(tritset tritset) {
    for (int i = 0; i < tritset.getSize(); i++) {
        tritset[i] = ~static_cast<trit>(tritset[i]);
    }
    return tritset;
}

void tritset::shrink() {
    size_t new_size = 0;
    for (int i = size - 1; i >= 0; i--) {
        if ((*this)[i] == Unknown) new_size++;
        else break;
    }
    new_size = size - new_size;
    realloc(new_size);
}

size_t tritset::cardinality(trit trit) {
    size_t count = 0;
    for (size_t i = 0; i < size; i++) {
        if ((*this)[i] == trit)count++;
    }
    return count;
}

void tritset::trim(size_t lastIndex) {
    if (lastIndex < size)realloc(lastIndex);
}