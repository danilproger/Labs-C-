//
// Created by danil on 19.09.2019.

//
#include "tritset.h"
#include <algorithm>

constexpr size_t allocated_memory(size_t size) {
    if (size < 16) return 1;
    if (!(2 * size / 8 % sizeof(uint))) return 2 * size / 8 / sizeof(uint);
    return 2 * size / 8 / sizeof(uint) + 1;
}

constexpr size_t trit_position(size_t pos) {
    return pos % (sizeof(uint) * 4);
}

constexpr size_t word_position(size_t pos) {
    return pos / (sizeof(uint) * 4);
}

tritset::tritset(size_t size) {
    tritset::size = size;
    tritset::capacity = allocated_memory(size);
    tritset::trits = new uint[capacity];
    std::fill(trits, trits + capacity, 0);
}

tritset::tritset(const tritset &tritset) {
    size = tritset.size;
    capacity = tritset.capacity;
    trits = new uint[capacity];
    for (int i = 0; i < capacity; i++) {
        trits[i] = tritset.trits[i];
    }
}

tritset::tritset(tritset &&tritset) {
    size = tritset.size;
    capacity = tritset.capacity;
    trits = tritset.trits;
    tritset.trits = nullptr;
}

tritset &tritset::operator=(const tritset &tritset) {
    if (this != &tritset) {
        capacity = tritset.capacity;
        size = tritset.size;
        delete[] trits;
        trits = new uint[capacity];
        for (int i = 0; i < capacity; i++) {
            trits[i] = tritset.trits[i];
        }
    }
    return *this;
}

tritset &tritset::operator=(tritset &&tritset) {
    if (this != &tritset) {
        capacity = tritset.capacity;
        size = tritset.size;
        delete[] trits;
        trits = tritset.trits;
        tritset.trits = nullptr;
    }
    return *this;
}

tritset::~tritset() {
    delete[]trits;
}

void tritset::realloc(size_t new_size) {
    tritset new_tritset(new_size);
    for (int i = 0; i < std::min(size, new_size); ++i) {
        new_tritset[i] = (*this)[i];
    }
    std::swap((*this), new_tritset);
}

size_t tritset::getSize() const {
    return size;
}

size_t tritset::getCapacity() const {
    return capacity;
}

tritset::reference::reference(tritset &tritset, size_t pos) {
    pTritset = &tritset;
    trit_pos = pos;
}

tritset::reference tritset::operator[](size_t key) {
    return reference(*this, key);
}

tritset::reference::operator trit() const {
    if (trit_pos >= pTritset->size) return Unknown;
    return static_cast<trit>(static_cast<uint>(3 & (*(pTritset->trits + word_position(trit_pos))
            >> trit_position(trit_pos) * 2)));
}

tritset::reference &tritset::reference::operator=(const trit &x) {
    if (trit_pos >= pTritset->size) {
        if (x == trit::Unknown) return *this;
        (*pTritset).realloc(trit_pos);
    }
    *(pTritset->trits + word_position(trit_pos)) =
            ((~(static_cast<uint>(3) << trit_position(trit_pos) * 2)) & *(pTritset->trits + word_position(trit_pos))) |
            (static_cast<uint>(x) << (trit_position(trit_pos) * 2));
    return *this;
}

tritset::reference &tritset::reference::operator=(const tritset::reference &x) {
    *this = static_cast<trit>(x);
    return *this;
}

tritset operator&(tritset &left, tritset &right) {
    size_t size = std::max(left.getSize(), right.getSize());
    tritset result(size);
    for (int i = 0; i < size; i++) {
        result[i] = (left[i] & right[i]);
    }
    return result;
}

tritset operator|(tritset &left, tritset &right) {
    size_t size = std::max(left.getSize(), right.getSize());
    tritset result(size);
    for (int i = 0; i < size; i++) {
        result[i] = (left[i] | right[i]);
    }
    return result;
}

tritset operator~(tritset &x) {
    size_t size = x.size;
    tritset result(size);
    for (int i = 0; i < size; i++) {
        result[i] = ~x[i];
    }
    return result;
}

void tritset::shrink() {
    size_t new_size = 0;
    for (int i = size - 1; i >= 0; i--) {
        if ((*this)[i] == trit::Unknown) new_size++;
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
    if (lastIndex < size) realloc(lastIndex);
}