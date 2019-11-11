//
// Created by danil on 04.11.2019.
//

#ifndef LAB2_PARSER_H
#define LAB2_PARSER_H


#include <string>
#include <unordered_map>
#include <vector>
#include "../Interfaces/IParser.h"

class Parser : public IParser{
private:
    std::unordered_map<std::string, std::vector<std::string>> _blocks;
    std::vector<std::string> _commands;
public:
    const std::vector<std::string> &getCommands() const;
    const std::unordered_map<std::string, std::vector<std::string>> &getBlocks() const;
    void parse(const std::string &fileName) override;
};


#endif //LAB2_PARSER_H
