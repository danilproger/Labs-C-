//
// Created by danil on 04.11.2019.
//

#ifndef LAB2_GREPBLOCK_H
#define LAB2_GREPBLOCK_H

#include "../Interfaces/IBlock.h"

class GrepBlock : public IBlock{
    std::vector<std::string> execute(std::vector<std::string> &text, std::vector<std::string> &args) const override;
};


#endif //LAB2_GREPBLOCK_H
