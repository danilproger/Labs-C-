//
// Created by danil on 03.11.2019.
//

#ifndef LAB2_BLOCKFACTORY_H
#define LAB2_BLOCKFACTORY_H


#include "../Interfaces/IBlock.h"
#include "../Interfaces/IBlockMaker.h"
#include <map>

class BlockFactory {
public:
    static BlockFactory &getInstance();

    IBlock *create(const std::string &blockName) const;

    void RegisterMaker(const std::string &blockName, IBlockMaker *maker);

private:
    BlockFactory();
    std::map<std::string, IBlockMaker *> _makers;
};


#endif //LAB2_BLOCKFACTORY_H
