#ifndef LOGILANG_LOGISOLVER_H
#define LOGILANG_LOGISOLVER_H

#include <vector>
#include <regex>

#include "LogicVar.h"
#include "LogicGraphNode.h"

class LogiSolver {
private:
    std::vector<LogicVar*> variables;
    std::vector<LogicGraphNode*> graphNodes;
public:
    LogiSolver();
    void ScanLine();
};


#endif //LOGILANG_LOGISOLVER_H
