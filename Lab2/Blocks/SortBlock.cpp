//
// Created by danil on 03.11.2019.
//

#include <algorithm>
#include "SortBlock.h"
#include "../Factory/BlockMaker.h"

REGISTER_SHAPE(SortBlock);

std::vector<std::string>
SortBlock::execute(std::vector<std::string> &text, std::vector<std::string> &args) const {
    std::sort(text.begin(), text.end());

    return text;
}
