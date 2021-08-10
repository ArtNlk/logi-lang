#include "LogiSolver.h"

std::string LogiSolver::validLineRegex = "^\\s*(\\w+)\\s*:=\\s*(\\w+\\((.*)\\))(\\n|$)";
char LogiSolver::commentChar = ';';

void LogiSolver::parseLine(const std::string& line) {
    //TODO Use map for operator lookup
    if(line.at(0) == LogiSolver::commentChar)
    {
        return;
    }
    std::regex lineRegex = std::regex(LogiSolver::validLineRegex);
    std::smatch match;
    if(!std::regex_match(line, match, lineRegex))
    {
        return;
    }

    LogicGraphNode* targetNode = nodeFromVarName(match.str(1));
    if(targetNode == nullptr)
    {
        addVar(match.str(1));
    }

    switch(opTypeFromCmdString(match.str(2)))
    {
        case TRUE_OP:
            targetNode->addOperator(new TrueOp());
            break;

        case REQUEST_OP:
            targetNode->addOperator(new RequestOp(match.str(1)));
            break;

        case CONDITIONAL_OP:

    }
}

operatorType LogiSolver::opTypeFromCmdString(const std::string& cmdString) {
    if(TrueOp::foundInCommandString(cmdString))
    {
        return TRUE_OP;
    } else if(RequestOp::foundInCommandString(cmdString))
    {
        return REQUEST_OP;
    } else if(ConditionalOp::foundInCommandString(cmdString))
    {
        return CONDITIONAL_OP;
    }

    return INVALID_OP;
}

LogicGraphNode *LogiSolver::nodeFromVarName(const std::string &varName) {
    for(auto graphNodePtr : this->graphNodes)
    {
        if(graphNodePtr->getVarName() == varName)
        {
            return graphNodePtr;
        }
    }

    return nullptr;
}

void LogiSolver::addVar(const std::string &varName) {
    if(nodeFromVarName(varName) != nullptr)
    {
        return;
    }

    this->graphNodes.push_back(new LogicGraphNode(varName));
}
