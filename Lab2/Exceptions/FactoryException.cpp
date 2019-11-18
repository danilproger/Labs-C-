//
// Created by danil on 18.11.2019.
//

#include "FactoryException.h"

FactoryException::FactoryException(const std::string &error) {
    _error = error;
}

const char *FactoryException::what() noexcept {
    return _error.c_str();
}
