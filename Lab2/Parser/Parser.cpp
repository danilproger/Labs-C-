//
// Created by danil on 11.11.2019.
//

#include "Parser.h"
#include "../Exceptions/ParserException.h"
#include <fstream>
#include <boost/tokenizer.hpp>
#include <exception>
#include <unordered_map>

#define EXCEPTION_ID(LINE, ID) "Exception in workflow, line: " + std::to_string(LINE) + ", id " + ID + " already exist\n"
#define EXCEPTION_ID_NOT_EXISTS(LINE, ID) "Exception in workflow, line: " + std::to_string(LINE) + ", id " + ID + " doesn't exist\n"
#define EXCEPTION_DESC(LINE) "Exception in workflow, line: " + std::to_string(LINE) + ", skipped desc\n"
#define EXCEPTION_CSED(LINE) "Exception in workflow, line: " + std::to_string(LINE) + ", skipped csed at the end\n"
#define EXCEPTION_COMM_SEQ(LINE) "Exception in workflow, line: " + std::to_string(LINE) + "\n"

void Parser::parse(const std::string &fileName) {
    bool check_csed = true;
    size_t lineCounter = 0, wordCounter = 0;
    std::ifstream ifstream;
    std::string line = "";
    std::vector<std::string> tokens;
    boost::char_separator<char> sep{" \t"};

    ifstream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        ifstream.open(fileName);
    } catch (std::ifstream::failure &e) {
        std::cerr << "Exception opening file " << fileName << std::endl;
    }

    std::getline(ifstream, line);
    if (line != "desc") {
        throw ParserException(EXCEPTION_DESC(lineCounter + 1));
    }
    lineCounter++;

    while (!ifstream.eof()) {
        std::getline(ifstream, line);
        boost::tokenizer<boost::char_separator<char>> tok{line, sep};

        if (line == "") continue;

        for (auto i : tok) {
            tokens.push_back(i);
        }

        if (tokens.size() < 3) {
            if (tokens.size() == 1 && tokens[0] == "csed") {
                check_csed = false;
                break;
            } else throw ParserException(EXCEPTION_COMM_SEQ(lineCounter + 1));
        }

        if (_blocks.find(tokens[0]) != _blocks.end())
            throw ParserException(EXCEPTION_ID(lineCounter + 1, tokens[0]));

        _blocks[tokens[0]] = std::vector<std::string>(tokens.begin() + 2, tokens.end());

        tokens.clear();
        lineCounter++;
    }

    if (check_csed) throw ParserException(EXCEPTION_CSED(lineCounter));

    line.clear();
    std::getline(ifstream, line);

    if (line == "") throw ParserException(EXCEPTION_COMM_SEQ(lineCounter + 1));

    boost::tokenizer<boost::char_separator<char>> tok{line, sep};

    lineCounter++;

    for (auto i: tok) {
        if (wordCounter % 2 != 0 && i != "->") throw ParserException(EXCEPTION_COMM_SEQ(lineCounter + 1));

        if (wordCounter % 2 == 0 && _blocks.find(i) == _blocks.end())
            throw ParserException(EXCEPTION_ID_NOT_EXISTS(lineCounter + 1, i));

        if (wordCounter % 2 == 0 && i != "->") {
            _commands.push_back(i);
        }

        wordCounter++;
    }

}

const std::unordered_map<std::string, std::vector<std::string>> &Parser::getBlocks() const {
    return _blocks;
}

const std::vector<std::string> &Parser::getCommands() const {
    return _commands;
}