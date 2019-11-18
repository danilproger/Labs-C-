//
// Created by danil on 03.11.2019.
//

#include <algorithm>
#include "SortBlock.h"
#include "../Factory/BlockMaker.h"

REGISTER_BLOCK(SortBlock, sort);

void SortBlock::execute(std::vector<std::string> &text, const std::vector<std::string> &args) const {
    std::sort(text.begin(), text.end());
}

const blockType SortBlock::getType() const {
    return OTHER;
}
