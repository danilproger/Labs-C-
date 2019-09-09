//
// Created by danil on 06.09.2019.
//

#include "word_counter.h"
#include <map>
#include <algorithm>

bool isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '\'');
}

word_counter::word_counter() {
    cnt = 0;
}

void word_counter::count(const std::string& fileName) {
    std::ifstream ifstream(fileName);
    std::map<std::string, int> word_pairs;
    std::string line;

    while (!ifstream.eof()) {
        std::getline(ifstream, line);
        std::string word;
        for (int i = 0; i < line.length(); i++) {
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

    for (std::pair<std::string, int> pair : word_pairs) {
        word_counter::freqencies.emplace_back(pair.second, pair.first);
    }
    ifstream.close();
}

void word_counter::write(const std::string& fileName) {
    std::ofstream ofstream(fileName);
    std::sort(freqencies.begin(), freqencies.end());
    std::reverse(freqencies.begin(), freqencies.end());
    for (const std::pair<int, std::string>& pair : freqencies) {
        ofstream << pair.second + ";" + std::to_string(pair.first) + ";" + std::to_string(100. * pair.first / (1.*cnt))  + '\n';
    }
    ofstream.close();
}

void word_counter::clear(){
    freqencies.clear();
}