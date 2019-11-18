//
// Created by danil on 03.11.2019.
//

#ifndef LAB2_BLOCKMAKER_H
#define LAB2_BLOCKMAKER_H

#include "../Interfaces/IBlockMaker.h"
#include "BlockFactory.h"

template<typename T>
class BlockMaker : public IBlockMaker {
public:
    BlockMaker(const std::string &blockName){
        BlockFactory::getInstance().RegisterMaker(blockName, this);
    }
    IBlock *create(const std::string &blockName) const override {
        return new T;
    }
};

#endif //LAB2_BLOCKMAKER_H
