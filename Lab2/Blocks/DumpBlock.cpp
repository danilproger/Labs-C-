//
// Created by danil on 04.11.2019.
//

#include <fstream>
#include <iostream>
#include "../Factory/BlockMaker.h"
#include "DumpBlock.h"
#include "../Exceptions/WorkFlowException.h"

REGISTER_BLOCK(DumpBlock, dump);

void DumpBlock::execute(std::vector<std::string> &text, const std::vector<std::string> &args) const {
    if(args.size()!=1) throw WorkFlowException("Args for dump != 1");
    std::string fileName = args[0];
    std::ofstream ofstream;
    ofstream.exceptions ( std::ofstream::failbit | std::ofstream::badbit );


    try {
        ofstream.open(fileName, std::fstream::out);
    } catch (std::ofstream::failure &e) {
        std::cerr << "Exception opening file " << fileName << std::endl;
    }

    for (auto i: text){
        ofstream<<i<<std::endl;
    }
}

const blockType DumpBlock::getType() const {
    return OUT_TYPE;
}
