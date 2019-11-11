//
// Created by danil on 11.11.2019.
//

#ifndef LAB2_IPARSER_H
#define LAB2_IPARSER_H

#include <iostream>

class IParser {
    virtual void parse(const std::string &fileName) = 0;
};
#endif //LAB2_IPARSER_H
