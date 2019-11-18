//
// Created by danil on 03.11.2019.
//

#include "WorkFlow.h"
#include "../Parser/Parser.h"
#include "../Factory/BlockFactory.h"
#include "../Exceptions/ParserException.h"
#include "../Exceptions/WorkFlowException.h"

WorkFlow::WorkFlow(const std::string &workFlow) {
    _workFlow = workFlow;
}

void WorkFlow::run() {
    Parser parser;
    std::vector<std::string> text;

    try {
        parser.parse(_workFlow);
    } catch (ParserException &e) {
        std::cerr << e.what();
        return;
    }

    auto blocks = parser.getBlocks();
    auto commands = parser.getCommands();

    for (size_t i = 0; i < commands.size(); i++) {
        std::string blockName = blocks[commands[i]][0];
        std::vector<std::string> args(blocks[commands[i]].begin() + 1, blocks[commands[i]].end());
        auto *block = BlockFactory::getInstance().create(blockName);

        if (i == 0 && block->getType() != IN_TYPE)
            throw WorkFlowException("Exception while running, first should be in block");
        if (i == commands.size() - 1 && block->getType() != OUT_TYPE)
            throw WorkFlowException("Exception while running, last should be out block");

        block->execute(text, args);
        delete block;
    }
}
