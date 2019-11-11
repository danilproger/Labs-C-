//
// Created by danil on 11.11.2019.
//

#ifndef LAB2_WORKFLOWEXCEPTION_H
#define LAB2_WORKFLOWEXCEPTION_H

#include <exception>
#include <iostream>
class WorkFlowException : public std::exception {
private:
    std::string _error;
public:
    WorkFlowException(const std::string &error);
    const char* what() noexcept;
};


#endif //LAB2_WORKFLOWEXCEPTION_H
