//
// Created by danil on 28.10.2019.
//
#include <vector>
#include <string>

#ifndef LAB2_BLOCK_H
#define LAB2_BLOCK_H
#define REGISTER_SHAPE(T) static BlockMaker<T> maker(#T)

class IBlock {
public:
    virtual std::vector<std::string> execute(std::vector<std::string> &text, std::vector<std::string> &args) const = 0;

    virtual ~IBlock() {};
};

#endif //LAB2_BLOCK_H