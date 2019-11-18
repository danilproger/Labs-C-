//
// Created by danil on 03.11.2019.
//

#include "BlockFactory.h"
#include "../Exceptions/FactoryException.h"

BlockFactory &BlockFactory::getInstance() {
    static BlockFactory factory;
    return factory;
}

IBlock *BlockFactory::create(const std::string &blockName) const {
    auto i = _makers.find(blockName);
    if (i == _makers.end()) {
        throw FactoryException("Cannot find block name: " + blockName);
    }
    IBlockMaker *maker = i->second;
    return maker->create(blockName);
}

void BlockFactory::RegisterMaker(const std::string &blockName, IBlockMaker *maker) {
    if (_makers.find(blockName) != _makers.end()) {
        throw FactoryException("Block already exists: " + blockName);
    }
    _makers[blockName] = maker;
}

BlockFactory::BlockFactory() {}
