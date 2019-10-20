//
// Created by danil on 19.09.2019.
//

#ifndef LAB1_TRITSET_H
#define LAB1_TRITSET_H

#include "trit.h"

using size_t = unsigned long long;
using uint = unsigned int;

class tritset {
    class reference {
        friend class tritset;

        size_t trit_pos;
        tritset *pTritset;

    public:
        reference(tritset &tritset, size_t pos);

        reference &operator=(const trit &x);

        reference &operator=(const reference &x);

        operator trit() const;
    };

private:
    uint *pTrits;
public:
    uint *getPTrits() const;

private:
    size_t capacity;
    size_t size;

    void realloc(size_t new_size);

public:
    size_t getSize() const;

    size_t getCapacity() const;

    size_t cardinality(trit trit);

    void trim(size_t lastIndex);

    void shrink();

    tritset(size_t size);

    tritset(const tritset &tritset);

    tritset(tritset &&tritset);

    ~tritset();

    tritset &operator=(const tritset &tritset);

    tritset &operator=(tritset &&tritset);

    reference operator[](size_t key);

    friend tritset operator&(tritset &tritset1, tritset &tritset2);

    friend tritset operator|(tritset &tritset1, tritset &tritset2);

    friend tritset operator~(tritset &tritset);
};


#endif //LAB1_TRITSET_H
