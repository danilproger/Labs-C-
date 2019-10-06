//
// Created by danil on 19.09.2019.
//

#ifndef LAB1_TRITSET_H
#define LAB1_TRITSET_H

#include <cstdio>
#include <vector>
#include <bitset>
#include "trit.h"

using uint = unsigned int;

constexpr size_t trit_position(size_t pos) {
    return pos % (sizeof(uint) * 4);
}

constexpr size_t word_position(size_t pos) {
    return pos / (sizeof(uint) * 4);
}

class tritset {
    class reference {
        friend class tritset;

        size_t trit_pos;
        tritset *trits;

    public:
        reference(tritset &tritset, size_t pos);

        reference &operator=(trit x);

        reference &operator=(const reference &x);

        operator trit() {
            return static_cast<trit>(static_cast<uint>(3 & (*(trits->trits+word_position(trit_pos)) >> trit_position(trit_pos) * 2)));
        }
    };
    friend class reference;
private:
    uint *trits;
    size_t capacity;
    size_t size;

    void realloc(size_t new_size);

public:
    size_t getSize() const;

    uint *getAr() { return trits; }

    size_t getCapacity() const;

    size_t cardinality(trit trit);

    void trim(size_t lastIndex);

    void shrink();

    tritset(size_t size);

    ~tritset();

    reference operator[](size_t key);
};

tritset operator&(tritset tritset1, tritset tritset2);

tritset operator|(tritset tritset1, tritset tritset2);

tritset operator~(tritset tritset);

#endif //LAB1_TRITSET_H
