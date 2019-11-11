//
// Created by danil on 11.11.2019.
//

#include "WorkFlowException.h"

WorkFlowException::WorkFlowException(const std::string &error) {
    _error = error;
}

const char *WorkFlowException::what() noexcept {
    return _error.c_str();
}
