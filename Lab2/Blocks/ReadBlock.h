//
// Created by danil on 04.11.2019.
//

#ifndef LAB2_READBLOCK_H
#define LAB2_READBLOCK_H

#include "../Interfaces/IBlock.h"

class ReadBlock : public IBlock{
    void execute(std::vector<std::string> &text, const std::vector<std::string> &args) const override;
    const blockType getType() const override;
};


#endif //LAB2_READBLOCK_H
