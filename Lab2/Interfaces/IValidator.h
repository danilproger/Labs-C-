//
// Created by danil on 11.11.2019.
//

#ifndef LAB2_IVALIDATOR_H
#define LAB2_IVALIDATOR_H

#include <iostream>

class IValidator{
    virtual void validate(const std::string &fileName) = 0;
};
#endif //LAB2_IVALIDATOR_H
