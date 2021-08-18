#include "LogicGraphNode.h"

LogicGraphNode::LogicGraphNode(const std::string& varName) {
    this->targetVariable = new LogicVar(varName);
    this->status = DFS_NOT_VISITED;
}

LogicGraphNode::~LogicGraphNode() {
    delete this->targetVariable;
    for(int i = 0; i < this->appliedOperators.size(); i++)
    {
        delete this->appliedOperators.at(i);
    }
}

void LogicGraphNode::addOperator(Operator* newOp) {
    if(newOp == nullptr)
    {
        throw std::invalid_argument("Logic graph node: add operator: operator pointer is NULL");
    }
    this->appliedOperators.push_back(newOp);
}

bool LogicGraphNode::eval() {
    if(this->targetVariable->isEvaluated())
    {
        return this->targetVariable->value;
    }
    std::cout << "Evaluating " << this->getVarName() << "\n";
    for(int i = 0; i < this->appliedOperators.size(); i++)
    {
        if(this->appliedOperators.at(i)->eval())
        {
            this->targetVariable->value = true;
            std::cout << "Finished evaluating " << this->getVarName() << " true term encountered" << "\n";
            return this->targetVariable->value;
        }
    }
    std::cout << "Finished evaluating " << this->getVarName() << " no true terms found" << "\n";
    this->targetVariable->markEvaluated();
    this->targetVariable->value = false;
    return this->targetVariable->value;
}

bool LogicGraphNode::isEvaluated() {
    return this->targetVariable->isEvaluated();
}

const std::string &LogicGraphNode::getVarName() {
    return this->targetVariable->getName();
}

DFSStatus LogicGraphNode::getDFSStatus() {
    return this->status;
}

void LogicGraphNode::DFSmarkInStack() {
    this->status = DFS_IN_STACK;
}

void LogicGraphNode::DFSmarkDone() {
    this->status = DFS_DONE;
}

std::vector<LogicGraphNode *> LogicGraphNode::getAdjacentNodes() {
    std::vector<LogicGraphNode *> adjacentNodes = std::vector<LogicGraphNode *>();
    std::vector<LogicGraphNode *> temp = std::vector<LogicGraphNode *>();
    for(int i = 0 ; i < this->appliedOperators.size(); i++)
    {
        temp = this->appliedOperators.at(i)->getRequiredNodes();
        std::copy(std::begin(temp),
                std::end(temp),
                std::back_inserter(adjacentNodes));
    }

    return adjacentNodes;
}
