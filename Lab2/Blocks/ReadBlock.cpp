//
// Created by danil on 04.11.2019.
//

#include <fstream>
#include <iostream>
#include "../Factory/BlockMaker.h"
#include "ReadBlock.h"

REGISTER_SHAPE(ReadBlock);

std::vector<std::string> ReadBlock::execute(std::vector<std::string> &text, std::vector<std::string> &args) const {
    std::string fileName = args[0], line;
    std::ifstream ifstream;

    try {
        ifstream.open(fileName, std::fstream::in);
    } catch (std::ifstream::failure e) {
        std::cerr << "Exception opening file " << fileName << std::endl;
    }

    text.clear();

    while(!ifstream.eof()){
        std::getline(ifstream, line);
        text.push_back(line);
    }

    return text;
}
