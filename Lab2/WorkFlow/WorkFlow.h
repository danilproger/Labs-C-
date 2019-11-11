//
// Created by danil on 03.11.2019.
//

#ifndef LAB2_WORKFLOW_H
#define LAB2_WORKFLOW_H


#include <string>
#include "../Interfaces/IWorkFlow.h"

class WorkFlow : public IWorkFlow{
private:
    std::string _workFlow;
public:
    WorkFlow(const std::string &workFlow);

    void run() override;
};


#endif //LAB2_WORKFLOW_H
