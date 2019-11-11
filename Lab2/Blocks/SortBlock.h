//
// Created by danil on 03.11.2019.
//

#ifndef LAB2_SORTBLOCK_H
#define LAB2_SORTBLOCK_H


#include "../Interfaces/IBlock.h"

class SortBlock : public IBlock {
    std::vector<std::string> execute(std::vector<std::string> &text, std::vector<std::string> &args) const override;
};


#endif //LAB2_SORTBLOCK_H
