//
// Created by danil on 11.11.2019.
//

#ifndef LAB2_PARSEREXCEPTION_H
#define LAB2_PARSEREXCEPTION_H


#include <exception>
#include <iostream>
class ParserException: public std::exception {
private:
    std::string _error;
public:
    ParserException(const std::string &error);
    const char* what() const noexcept;
};


#endif //LAB2_PARSEREXCEPTION_H
