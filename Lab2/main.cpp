#include "WorkFlow/WorkFlow.h"
#include "Exceptions/WorkFlowException.h"
#include "Exceptions/FactoryException.h"
#include <iostream>

int main(int argc, char **argv) {
    if (argc <= 1) {
        std::cerr << "Use pattern \'prog workflow.txt\'";
    }

    WorkFlow workFlow(argv[1]);
    
    try {
        workFlow.run();
    } catch (FactoryException &e) {
        std::cerr << e.what();
    } catch (WorkFlowException &e) {
        std::cerr << e.what();
    }


    return 0;
}