//
// Created by danil on 11.11.2019.
//

#include "ParserException.h"

ParserException::ParserException(const std::string &error) {
    _error = error;
}

const char *ParserException::what() const noexcept {
    return _error.c_str();
}
