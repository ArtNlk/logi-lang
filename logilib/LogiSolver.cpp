#include "LogiSolver.h"

std::string LogiSolver::validLineRegex = "^\\s*(\\w+)\\s*:=\\s*((\\w+)\\((.*)\\))(\\n|$)";

std::map<std::string, operatorType> LogiSolver::operatorMap = LogiSolver::populateOperatorMap();


char LogiSolver::commentChar = ';';

bool LogiSolver::parseLine(const std::string& line) {
    //TODO Use map for operator lookup
    if(line.at(0) == LogiSolver::commentChar)
    {
        lastError = LINE_IS_COMMENT;
        return false;
    }
    std::regex lineRegex = std::regex(LogiSolver::validLineRegex);
    std::smatch match;
    if(!std::regex_match(line, match, lineRegex))
    {
        lastError = LINE_SYNTAX_INVALID;
        return false;
    }

    LogicGraphNode* targetNode = nodeFromVarName(match.str(1));
    if(targetNode == nullptr)
    {
        addVar(match.str(1));
    }

    auto opTypeIter = operatorMap.find(match.str(3));
    if (opTypeIter != operatorMap.end())
    {
        switch (opTypeIter->second) {
            default:
                throw std::logic_error("LogiSolver: operator not handled by switch-case");
                break;

            case TRUE_OP:
                targetNode->addOperator(new TrueOp());
                break;

            case REQUEST_OP:
                targetNode->addOperator(new RequestOp(match.str(1)));
                break;

            case CONDITIONAL_OP:
                std::vector<std::string> requiredVarNames = ConditionalOp::paramStringToVarNames(match.str(4));
                std::vector<LogicGraphNode*> requiredNodes = std::vector<LogicGraphNode*>();

                for(int i = 0; i < requiredVarNames.size(); i++)
                {
                    LogicGraphNode* foundNode = nodeFromVarName(requiredVarNames.at(i));
                    if(foundNode == nullptr)
                    {
                        lastError = CONDITIONAL_VAR_NOT_FOUND;
                        return false;
                    }
                    requiredNodes.push_back(foundNode);
                }

                targetNode->addOperator(new ConditionalOp(requiredNodes));
                break;
        }
    }

}

LogicGraphNode* LogiSolver::nodeFromVarName(const std::string &varName) {
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

std::map<std::string, operatorType> LogiSolver::populateOperatorMap() {
    std::map<std::string, operatorType> newMap = std::map<std::string, operatorType>();
    newMap.insert(std::make_pair(TrueOp::operatorName,TRUE_OP));
    newMap.insert(std::make_pair(RequestOp::operatorName,REQUEST_OP));
    newMap.insert(std::make_pair(ConditionalOp::operatorName,CONDITIONAL_OP));

    return newMap;
}
