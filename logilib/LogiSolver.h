#ifndef LOGILANG_LOGISOLVER_H
#define LOGILANG_LOGISOLVER_H

#include <vector>
#include <stack>
#include <regex>
#include <stdexcept>

#include "LogicVar.h"
#include "LogicGraphNode.h"
#include "operators.h"

enum solverStatus{NO_ERROR,CONDITIONAL_VAR_NOT_FOUND,LINE_SYNTAX_INVALID,LINE_IS_COMMENT,CYCLE_DETECTED, SOLVER_VAR_NOT_FOUND, LINE_IS_EMPTY};

class LogiSolver {
private:
    static std::string validLineRegex;
    static char commentChar;
    static std::map<std::string, operatorType> operatorMap;
    std::vector<LogicGraphNode*> graphNodes;
    solverStatus lastStatus;
    std::vector<std::string> foundCycle;

public:
    LogiSolver() = default;
    ~LogiSolver();
    bool parseLine(const std::string& line);
    bool solveFor(std::string targetVarName);
    bool findCycles();
    LogicGraphNode* addVar(const std::string& varName);
    solverStatus getLastError();
    std::vector<std::string> getCycleVarNames();

private:
    LogicGraphNode* nodeFromVarName(const std::string& varName);
    bool processDFSTree(std::stack<LogicGraphNode*> &visitedNodeStack, LogicGraphNode *node);
    std::vector<std::string> DFSstackToNodeNamelist(std::stack<LogicGraphNode*> cycleStack);
    static std::map<std::string, operatorType> populateOperatorMap();
};


#endif //LOGILANG_LOGISOLVER_H
