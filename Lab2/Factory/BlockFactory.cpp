//
// Created by danil on 03.11.2019.
//

#include "BlockFactory.h"

BlockFactory &BlockFactory::getInstance() {
    static BlockFactory factory;
    return factory;
}

IBlock *BlockFactory::create(const std::string &blockName) const {
    auto i = _makers.find(blockName);
    if (i == _makers.end()) {
        //throw
    }
    IBlockMaker *maker = i->second;
    return maker->Create(blockName);
}

void BlockFactory::RegisterMaker(const std::string &blockName, IBlockMaker *maker) {
    if (_makers.find(blockName) != _makers.end()) {
        //throw
    }
    _makers[blockName] = maker;
}
