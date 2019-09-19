//
// Created by danil on 06.09.2019.
//

#include "word_counter.h"
#include <vector>
#include <fstream>
#include <algorithm>

bool isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

bool cmp(const std::pair<std::string, int> &left, const std::pair<std::string, int> &right){
    return left.second > right.second;
}

word_counter::word_counter() {
    size = 0;
}

void word_counter::count(const std::string &fileName) {
    std::ifstream ifstream(fileName);
    std::string line;

    while (!ifstream.eof()) {
        std::getline(ifstream, line);
        std::string word;
        for (size_t i = 0; i < line.length(); i++) {
            line[i] = tolower(line[i]);
            while (isLetter(line[i])) {
                word += line[i];
                i++;
            }
            if (!word.empty()) {
                freqencies[word]++;
                size++;
                word.clear();
            }
        }
    }
}

void word_counter::write(const std::string &fileName) {
    std::ofstream ofstream(fileName);
    std::vector<std::pair<std::string, int>> word_pairs;
    for (const auto &pair : freqencies) {
        word_pairs.emplace_back(pair.first, pair.second);
    }
    std::sort(word_pairs.begin(), word_pairs.end(), cmp);
    for (const auto &pair : word_pairs) {
        ofstream << pair.first + ";" + std::to_string(pair.second) + ";" +
                    std::to_string((long double) 100. * pair.second / size) + '\n';
    }
}

void word_counter::clear() {
    freqencies.clear();
}

unsigned long long word_counter::getSize() const {
    return size;
}