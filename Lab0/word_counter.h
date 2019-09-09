//
// Created by danil on 06.09.2019.
//

#ifndef LAB0_WORD_COUNTER_H
#define LAB0_WORD_COUNTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class word_counter {
public:
    word_counter();
    void count(const std::string& fileName);
    void write(const std::string& fileName);
    void clear();
private:
    unsigned long long cnt;
    std::vector<std::pair<int,std::string>> freqencies;
};


#endif //LAB0_WORD_COUNTER_H
