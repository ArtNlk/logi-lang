#ifndef LOGILANG_LOGISOLVER_H
#define LOGILANG_LOGISOLVER_H

#include <vector>
#include <stack>
#include <regex>

#include "LogicVar.h"
#include "LogicGraphNode.h"
#include "operators.h"

class LogiSolver {
private:
    static std::string validLineRegex;
    static char commentChar;
    std::vector<LogicGraphNode*> graphNodes;
public:
    LogiSolver() = default;
    void parseLine(const std::string& line);
    bool solveFor(std::string targetVarName);
    bool findCycles();
    void addVar(const std::string& varName);

private:
    static operatorType opTypeFromCmdString(const std::string& cmdString);
    LogicGraphNode* nodeFromVarName(const std::string& varName);
    bool processDFSTree();
    void printNodeCycle(std::stack<LogicGraphNode*> currentNodestack,LogicGraphNode* rootNode);
};


#endif //LOGILANG_LOGISOLVER_H
