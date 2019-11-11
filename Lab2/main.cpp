#include <iostream>
#include "WorkFlow/WorkFlow.h"
#include "Parser/Parser.h"

int main() {
    /*Parser parser;
    parser.parse("workflow.txt");
    parser.Write();*/
    WorkFlow workFlow("workflow.txt");
    workFlow.run();
    return 0;
}