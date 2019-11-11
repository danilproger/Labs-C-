//
// Created by danil on 11.11.2019.
//

#ifndef LAB2_VALIDATOREXCEPTION_H
#define LAB2_VALIDATOREXCEPTION_H


#include <exception>
#include <iostream>
class ValidatorException: public std::exception {
private:
    std::string _error;
public:
    ValidatorException(const std::string &error);
    const char* what() const noexcept;
};


#endif //LAB2_VALIDATOREXCEPTION_H
