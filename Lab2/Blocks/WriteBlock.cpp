//
// Created by danil on 04.11.2019.
//

#include <fstream>
#include <iostream>
#include "../Factory/BlockMaker.h"
#include "WriteBlock.h"
#include "../Exceptions/WorkFlowException.h"

REGISTER_BLOCK(WriteBlock, writefile);

void WriteBlock::execute(std::vector<std::string> &text, const std::vector<std::string> &args) const {
    if (args.size() != 1) throw WorkFlowException("Args for write != 1");
    std::string fileName = args[0];
    std::ofstream ofstream;
    ofstream.exceptions(std::ofstream::failbit | std::ofstream::badbit);

    try {
        ofstream.open(fileName, std::fstream::out);
    } catch (std::ofstream::failure &e) {
        std::cerr << "Exception opening file " << fileName << std::endl;
    }

    for (auto i: text) {
        ofstream << i << std::endl;
    }
    text.clear();
}

const blockType WriteBlock::getType() const {
    return OUT_TYPE;
}
