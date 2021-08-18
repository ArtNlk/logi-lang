#include "LogiSolver.h"

std::string LogiSolver::validLineRegex = "^\\s*(\\w+)\\s*=\\s*((\\w+)\\((.*)\\))(\\n|$)";

std::map<std::string, operatorType> LogiSolver::operatorMap = LogiSolver::populateOperatorMap();

LogiSolver::~LogiSolver() {
    for(int i = 0; i < this->graphNodes.size(); i++)
    {
        delete this->graphNodes.at(i);
    }
}

char LogiSolver::commentChar = ';';

bool LogiSolver::parseLine(const std::string& line) {
    if(line.empty())
    {
        lastStatus = LINE_IS_EMPTY;
        return false;
    }
    if(line.at(0) == LogiSolver::commentChar)
    {
        lastStatus = LINE_IS_COMMENT;
        return false;
    }
    std::regex lineRegex = std::regex(LogiSolver::validLineRegex);
    std::smatch match;
    if(!std::regex_match(line, match, lineRegex))
    {
        lastStatus = LINE_SYNTAX_INVALID;
        return false;
    }

    LogicGraphNode* targetNode = nodeFromVarName(match.str(1));
    if(targetNode == nullptr)
    {
        targetNode = addVar(match.str(1));
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
                        foundNode = addVar(requiredVarNames.at(i));
                    }
                    requiredNodes.push_back(foundNode);
                }

                targetNode->addOperator(new ConditionalOp(requiredNodes));
                break;
        }
    }

    return true;
}

bool LogiSolver::findCycles() {
    for(int i = 0; i < graphNodes.size(); i++)
    {
        if(graphNodes.at(i)->getDFSStatus() == DFS_NOT_VISITED)
        {
            std::stack<LogicGraphNode*> nodeStack = std::stack<LogicGraphNode*>();
            nodeStack.push(graphNodes.at(i));
            graphNodes.at(i)->DFSmarkInStack();
            if(processDFSTree(nodeStack,graphNodes.at(i)))
            {
                return true;
            }
        }
    }

    return false;
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

bool LogiSolver::processDFSTree(std::stack<LogicGraphNode *> &visitedNodeStack, LogicGraphNode *node) {
    std::vector<LogicGraphNode*> adjacentNodes = node->getAdjacentNodes();
    for(int i = 0; i < adjacentNodes.size(); i++)
    {
        if(adjacentNodes.at(i)->getDFSStatus() == DFS_IN_STACK)
        {
            this->foundCycle = DFSstackToNodeNamelist(visitedNodeStack);
            return true;
        } else if(adjacentNodes.at(i)->getDFSStatus() == DFS_NOT_VISITED)
        {
            visitedNodeStack.push(adjacentNodes.at(i));
            visitedNodeStack.top()->DFSmarkInStack();
            if(processDFSTree(visitedNodeStack,adjacentNodes.at(i)))
            {
                return true;
            }
        }
    }
    visitedNodeStack.top()->DFSmarkDone();
    visitedNodeStack.pop();
    return false;
}

LogicGraphNode* LogiSolver::addVar(const std::string &varName) {
    LogicGraphNode* existingNode = nodeFromVarName(varName);
    if(existingNode != nullptr)
    {
        return existingNode;
    }

    LogicGraphNode* newNode = new LogicGraphNode(varName);

    this->graphNodes.push_back(newNode);

    return newNode;
}

solverStatus LogiSolver::getLastError() {
    solverStatus temp = this->lastStatus;
    return temp;
}

std::vector<std::string> LogiSolver::getCycleVarNames() {
    return this->foundCycle;
}

std::map<std::string, operatorType> LogiSolver::populateOperatorMap() {
    std::map<std::string, operatorType> newMap = std::map<std::string, operatorType>();
    newMap.insert(std::make_pair(TrueOp::operatorName,TRUE_OP));
    newMap.insert(std::make_pair(RequestOp::operatorName,REQUEST_OP));
    newMap.insert(std::make_pair(ConditionalOp::operatorName,CONDITIONAL_OP));

    return newMap;
}

std::vector<std::string> LogiSolver::DFSstackToNodeNamelist(std::stack<LogicGraphNode *> cycleStack) {
    std::vector<std::string> nodeNames;
    for(int i = 0; i < cycleStack.size(); i++)
    {
        nodeNames.push_back(cycleStack.top()->getVarName());
        cycleStack.pop();
    }

    return nodeNames;
}

bool LogiSolver::solveFor(std::string targetVarName) {
    LogicGraphNode *targetNode = nodeFromVarName(targetVarName);
    if (targetNode == nullptr) {
        this->lastStatus = SOLVER_VAR_NOT_FOUND;
        throw std::invalid_argument("LogiSolver: attempt to solve for non-existent variable");
    }

    if (findCycles()) {
        this->lastStatus = CYCLE_DETECTED;
        throw std::logic_error("LogiSolver: definition graph contains cycles");
    }

    return targetNode->eval();
}
