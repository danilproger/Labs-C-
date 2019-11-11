//
// Created by danil on 04.11.2019.
//

#include <fstream>
#include <iostream>
#include "../Factory/BlockMaker.h"
#include "WriteBlock.h"

REGISTER_SHAPE(WriteBlock);

std::vector<std::string> WriteBlock::execute(std::vector<std::string> &text, std::vector<std::string> &args) const {
    std::string fileName = args[0];
    std::ofstream ofstream;

    try {
        ofstream.open(fileName, std::fstream::out);
    } catch (std::ofstream::failure e) {
        std::cerr << "Exception opening file " << fileName << std::endl;
    }

    for (auto i: text){
        ofstream<<i<<std::endl;
    }
    text.clear();

    return text;
}
