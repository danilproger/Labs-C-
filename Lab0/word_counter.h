//
// Created by danil on 06.09.2019.
//

#ifndef LAB0_WORD_COUNTER_H
#define LAB0_WORD_COUNTER_H

#include <iostream>
#include <string>
#include <map>

class word_counter {
public:
    word_counter();
    void count(const std::string& fileName);
    void write(const std::string& fileName);
    void clear();

    unsigned long long getSize() const;
private:
    unsigned long long size;
    std::map<std::string, int> freqencies;
};


#endif //LAB0_WORD_COUNTER_H
