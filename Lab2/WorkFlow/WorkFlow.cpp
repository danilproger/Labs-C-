//
// Created by danil on 03.11.2019.
//

#include "WorkFlow.h"
#include "../Parser/Parser.h"
#include "../Factory/BlockFactory.h"
#include "../Validator/Validator.h"
#include "../Exceptions/ValidatorException.h"
#include "../Exceptions/WorkFlowException.h"

std::string getBlockName(const std::string &commandName){
    if (commandName == "readfile") return "ReadBlock";
    if (commandName == "writefile") return "WriteBlock";
    if (commandName == "grep") return "GrepBlock";
    if (commandName == "sort") return "SortBlock";
    if (commandName == "replace") return "ReplaceBlock";
    if (commandName == "dump") return "DumpBlock";
    return "-1";
}

WorkFlow::WorkFlow(const std::string &workFlow) {
    _workFlow = workFlow;
}

void WorkFlow::run() {
    Parser parser;
    Validator validator;
    std::vector<std::string> text;

    try{
        validator.validate(_workFlow);
    } catch (ValidatorException e){
        std::cerr<<e.what();
        return;
    }

    parser.parse(_workFlow);

    auto map = parser.getBlocks();
    auto comm = parser.getCommands();

    try {
        for (auto i: comm) {
            std::string blockName = getBlockName(map[i][0]);
            std::vector<std::string> args(map[i].begin() + 1, map[i].end());
            text = BlockFactory::getInstance().create(blockName)->execute(text, args);
        }
    } catch (WorkFlowException e){
        std::cerr<<e.what();
    }
}
