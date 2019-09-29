//
// Created by danil on 19.09.2019.
//

#ifndef LAB1_TRITSET_H
#define LAB1_TRITSET_H

#include <cstdio>
#include <vector>
#include <bitset>

enum trit {
    Unknown, False, True
};

class tritset {
    class reference {
        friend class tritset;

        size_t trit_pos;
        unsigned int *word;

        reference();

    public:
        reference(tritset &tritset, size_t pos);

        reference &operator=(trit x);

        reference &operator=(const reference &x);

        operator trit() {
            return static_cast<trit>(static_cast<unsigned int>(3 & (*word >> trit_pos * 2)));
        }
    };

    friend class reference;

private:
    std::vector<unsigned int> trits;
    size_t capacity;
    size_t size;
public:
    std::vector<unsigned int> &getVec(){
        return trits;
    }
    tritset(size_t size);
    reference operator [] (size_t pos){
        return reference(*this, pos);
    }
    ~tritset();

};


#endif //LAB1_TRITSET_H
