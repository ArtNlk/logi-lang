#ifndef LOGILANG_LOGISOLVER_H
#define LOGILANG_LOGISOLVER_H

#include <vector>
#include <stack>
#include <regex>
#include <stdexcept>

#include "LogicVar.h"
#include "LogicGraphNode.h"
#include "operators.h"

enum solverError{NO_ERROR,CONDITIONAL_VAR_NOT_FOUND,LINE_SYNTAX_INVALID,LINE_IS_COMMENT};

class LogiSolver {
private:
    static std::string validLineRegex;
    static char commentChar;
    static std::map<std::string, operatorType> operatorMap;
    std::vector<LogicGraphNode*> graphNodes;
public:
    solverError lastError;
    LogiSolver() = default;
    bool parseLine(const std::string& line);
    bool solveFor(std::string targetVarName);
    bool findCycles();
    void addVar(const std::string& varName);

private:
    static operatorType opTypeFromCmdString(const std::string& cmdString);
    LogicGraphNode* nodeFromVarName(const std::string& varName);
    bool processDFSTree();
    void printNodeCycle(std::stack<LogicGraphNode*> currentNodestack,LogicGraphNode* rootNode);
    static std::map<std::string, operatorType> populateOperatorMap();
};


#endif //LOGILANG_LOGISOLVER_H
