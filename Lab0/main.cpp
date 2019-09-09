#include <iostream>
#include "word_counter.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << R"(please use pattern "program 'input.txt' 'output.csv'")";
        return 0;
    }
    auto *wordCounter = new word_counter;
    wordCounter->count(argv[1]);
    wordCounter->write(argv[2]);
    delete wordCounter;
    return 0;
}