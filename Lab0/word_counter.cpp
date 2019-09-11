//
// Created by danil on 06.09.2019.
//

#include "word_counter.h"
#include <map>
#include <fstream>
#include <algorithm>

bool isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '\'');
}

word_counter::word_counter() {
    cnt = 0;
}

word_counter::~word_counter() {
    freqencies.clear();
}

void word_counter::count(const std::string &fileName) {
    std::ifstream ifstream(fileName);
    std::map<std::string, int> word_pairs;
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
                word_pairs[word]++;
                cnt++;
                word.clear();
            }
        }
    }

    for (const auto &pair : word_pairs) {
        word_counter::freqencies.emplace_back(pair.second, pair.first);
    }
    ifstream.close();
}

void word_counter::write(const std::string &fileName) {
    std::ofstream ofstream(fileName);
    std::sort(freqencies.begin(), freqencies.end());
    std::reverse(freqencies.begin(), freqencies.end());
    for (const auto &pair : freqencies) {
        ofstream << pair.second + ";" + std::to_string(pair.first) + ";" +
                    std::to_string((double) 100 * pair.first / cnt) + '\n';
    }
    ofstream.close();
}

void word_counter::clear() {
    freqencies.clear();
}