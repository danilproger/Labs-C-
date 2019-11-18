//
// Created by danil on 11.11.2019.
//

#ifndef LAB2_PARSER_H
#define LAB2_PARSER_H

#include "../Interfaces/IParser.h"
#include <unordered_map>
#include <vector>

class Parser : public IParser {
private:
    std::unordered_map<std::string, std::vector<std::string>> _blocks;
    std::vector<std::string> _commands;
public:
    const std::unordered_map<std::string, std::vector<std::string>> &getBlocks() const;

    const std::vector<std::string> &getCommands() const;

    void parse(const std::string &fileName) override;
};


#endif //LAB2_PARSER_H
