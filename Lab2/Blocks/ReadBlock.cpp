//
// Created by danil on 04.11.2019.
//

#include <fstream>
#include <iostream>
#include "../Factory/BlockMaker.h"
#include "ReadBlock.h"
#include "../Exceptions/WorkFlowException.h"

REGISTER_BLOCK(ReadBlock, readfile);

void ReadBlock::execute(std::vector<std::string> &text, const std::vector<std::string> &args) const {
    if(args.size()!=1) throw WorkFlowException("Args for read != 1");
    std::string fileName = args[0], line;
    std::ifstream ifstream;
    ifstream.exceptions(std::ifstream::failbit | std::ifstream::badbit);


    try {
        ifstream.open(fileName, std::fstream::in);
    } catch (std::ifstream::failure &e) {
        std::cerr << "Exception opening file " << fileName << std::endl;
    }

    text.clear();

    while (!ifstream.eof()) {
        std::getline(ifstream, line);
        text.push_back(line);
    }

}

const blockType ReadBlock::getType() const {
    return IN_TYPE;
}
