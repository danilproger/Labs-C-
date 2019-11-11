//
// Created by danil on 03.11.2019.
//

#ifndef LAB2_IBLOCKMAKER_H
#define LAB2_IBLOCKMAKER_H

#include "IBlock.h"

class IBlockMaker {
public:
    virtual IBlock *Create(const std::string &blockName) const = 0;
};
#endif //LAB2_IBLOCKMAKER_H