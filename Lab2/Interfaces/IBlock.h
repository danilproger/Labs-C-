//
// Created by danil on 28.10.2019.
//
#include <vector>
#include <string>

#ifndef LAB2_BLOCK_H
#define LAB2_BLOCK_H
#define REGISTER_BLOCK(T, NAME) static BlockMaker<T> maker(#NAME)

enum blockType {
    IN_TYPE, OUT_TYPE, OTHER
};

class IBlock {

public:
    virtual void execute(std::vector<std::string> &text, const std::vector<std::string> &args) const = 0;

    virtual const blockType getType() const = 0;

    virtual ~IBlock() {};
};

#endif //LAB2_BLOCK_H