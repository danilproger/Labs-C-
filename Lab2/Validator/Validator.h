//
// Created by danil on 11.11.2019.
//

#ifndef LAB2_VALIDATOR_H
#define LAB2_VALIDATOR_H

#include "../Interfaces/IValidator.h"
#include <set>
#include <vector>

class Validator : public IValidator {
private:
    bool validateCommName(const std::string &commName);
    bool validateArgs(const std::vector<std::string> &args);
    std::set<std::string> _commNames{"readfile", "writefile", "grep", "sort", "replace", "dump"};
public:
    void validate(const std::string &fileName) override;
};


#endif //LAB2_VALIDATOR_H
