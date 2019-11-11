//
// Created by danil on 11.11.2019.
//

#include "Validator.h"
#include "../Exceptions/ValidatorException.h"
#include <fstream>
#include <boost/tokenizer.hpp>
#include <exception>
#include <unordered_map>

#define EXCEPTION_NAME(LINE, NAME) "Exception in line: " + std::to_string(LINE) + ", unknown command: " + NAME + "\n"
#define EXCEPTION_ARGS(LINE) "Exception in line: " + std::to_string(LINE) + ", amount of args\n"
#define EXCEPTION_ID(LINE, ID) "Exception in line: " + std::to_string(LINE) + ", id " + ID + " already exist\n"
#define EXCEPTION_DESC(LINE) "Exception in line: " + std::to_string(LINE) + ", skipped desc\n"
#define EXCEPTION_CSED(LINE) "Exception in line: " + std::to_string(LINE) + ", skipped csed at the end\n"
#define EXCEPTION_COMM_SEQ(LINE) "Exception in line: " + std::to_string(LINE) + "\n"
#define EXCEPTION_COMM_SEQ_FIRST(LINE) "Exception in line: " + std::to_string(LINE) + ", first should be readfile\n"
#define EXCEPTION_COMM_SEQ_LAST(LINE) "Exception in line: " + std::to_string(LINE) + ", last should be writefile\n"


bool Validator::validateCommName(const std::string &commName) {
    return _commNames.find(commName) == _commNames.end();
}

bool Validator::validateArgs(const std::vector<std::string> &args) {
    if (args[0] == "readfile" && args.size() == 3) return true;
    if (args[0] == "writefile" && args.size() == 3) return true;
    if (args[0] == "grep" && args.size() == 3) return true;
    if (args[0] == "sort" && args.size() == 2) return true;
    if (args[0] == "replace" && args.size() == 4) return true;
    if (args[0] == "dump" && args.size() == 3) return true;
    return false;
}

void Validator::validate(const std::string &fileName) {
    bool flag = true;
    size_t lineCounter = 0, wordCounter = 0, tokensSize;
    std::ifstream ifstream;
    std::string line = "";
    std::vector<std::string> tokens;
    std::unordered_map<std::string, std::string> blocks;
    boost::char_separator<char> sep{" "};

    try {
        ifstream.open(fileName, std::fstream::in);
    } catch (std::ifstream::failure e) {
        std::cerr << "Exception opening file " << fileName << std::endl;
    }

    std::getline(ifstream, line);
    if (line != "desc") {
        throw ValidatorException(EXCEPTION_DESC(lineCounter + 1));
    }
    lineCounter++;

    while (!ifstream.eof()) {
        std::getline(ifstream, line);

        if (line == "csed") {
            flag = false;
            break;
        }

        boost::tokenizer<boost::char_separator<char>> tok{line, sep};

        for (auto i : tok) {
            if (i != "=") tokens.push_back(i);
        }

        if (validateCommName(tokens[1])) throw ValidatorException(EXCEPTION_NAME(lineCounter + 1, tokens[1]));

        if (validateArgs(std::vector<std::string>(tokens.begin(), tokens.end())))
            throw ValidatorException(EXCEPTION_ARGS(lineCounter + 1));

        if (blocks.find(tokens[0]) == blocks.end()) {
            blocks[tokens[0]] = tokens[1];
        } else {
            throw ValidatorException(EXCEPTION_ID(lineCounter + 1, tokens[0]));
        }

        tokens.clear();
        lineCounter++;
    }
    if (flag) throw ValidatorException(EXCEPTION_CSED(lineCounter + 1));

    std::getline(ifstream, line);
    lineCounter++;
    boost::tokenizer<boost::char_separator<char>> tok{line, sep};
    tokensSize = std::distance(tok.begin(), tok.end());
    for (auto i: tok) {
        if (wordCounter == 0 && blocks[i] != "readfile")
            throw ValidatorException(EXCEPTION_COMM_SEQ_FIRST(lineCounter));
        if (wordCounter == tokensSize && blocks[i] != "writefile")
            throw ValidatorException(EXCEPTION_COMM_SEQ_LAST(lineCounter));
        if (wordCounter % 2 != 0 && i != "->") throw ValidatorException(EXCEPTION_COMM_SEQ(lineCounter + 1));
        if (wordCounter > 0 && wordCounter < tokensSize && wordCounter % 2 == 0) {
            if (blocks.find(i) == blocks.end()) throw ValidatorException(EXCEPTION_COMM_SEQ(lineCounter + 1));
        }
        wordCounter++;
    }
}
