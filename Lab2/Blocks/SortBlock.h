//
// Created by danil on 03.11.2019.
//

#ifndef LAB2_SORTBLOCK_H
#define LAB2_SORTBLOCK_H


#include "../Interfaces/IBlock.h"

class SortBlock : public IBlock {
    void execute(std::vector<std::string> &text, const std::vector<std::string> &args) const override;
    const blockType getType() const override;
};


#endif //LAB2_SORTBLOCK_H
