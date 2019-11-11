//
// Created by danil on 04.11.2019.
//

#include <fstream>
#include <boost/tokenizer.hpp>
#include "Parser.h"

void Parser::parse(const std::string &fileName) {
    std::ifstream ifstream;
    std::string line = "";
    std::vector<std::string> tokens;
    boost::char_separator<char> sep{" "};

    try {
        ifstream.open(fileName, std::fstream::in);
    } catch (std::ifstream::failure e) {
        std::cerr << "Exception opening file " << fileName << std::endl;
    }

    std::getline(ifstream, line);

    while (!ifstream.eof()) {
        std::getline(ifstream, line);
        if (line == "csed") break;
        boost::tokenizer<boost::char_separator<char>> tok{line, sep};
        for (auto i: tok) {
            tokens.push_back(i);
        }
        _blocks[tokens[0]] = std::vector<std::string>(tokens.begin() + 2, tokens.end());
        tokens.clear();
    }

    std::getline(ifstream, line);
    boost::tokenizer<boost::char_separator<char>> tok{line, sep};
    for (auto i: tok){
        if(i!="->") _commands.push_back(i);
    }
}

const std::vector<std::string> &Parser::getCommands() const {
    return _commands;
}

const std::unordered_map<std::string, std::vector<std::string>> &Parser::getBlocks() const {
    return _blocks;
}
