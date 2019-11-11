//
// Created by danil on 11.11.2019.
//

#include "ValidatorException.h"

ValidatorException::ValidatorException(const std::string &error) {
    _error = error;
}

const char *ValidatorException::what() const noexcept {
    return _error.c_str();
}
