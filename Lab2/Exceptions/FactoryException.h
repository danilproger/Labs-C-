//
// Created by danil on 18.11.2019.
//

#ifndef LAB2_FACTORYEXCEPTION_H
#define LAB2_FACTORYEXCEPTION_H

#include <exception>
#include <iostream>

class FactoryException : public std::exception {
private:
    std::string _error;
public:
    FactoryException(const std::string &error);
    const char* what() noexcept;
};


#endif //LAB2_FACTORYEXCEPTION_H
