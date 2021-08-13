#include "LogicGraphNode.h"

LogicGraphNode::LogicGraphNode(const std::string& varName) {
    this->targetVariable = new LogicVar(varName);
    this->status = DFS_NOT_VISITED;
}

LogicGraphNode::~LogicGraphNode() {
    delete this->targetVariable;
}

void LogicGraphNode::addOperator(Operator* newOp) {
    if(newOp == nullptr)
    {
        throw std::invalid_argument("Logic graph node: add operator: operator pointer is NULL");
    }
    this->appliedOperators.push_back(newOp);
}

bool LogicGraphNode::eval() {
    this->targetVariable->markEvaluated();
    for(int i = 0; i < this->appliedOperators.size(); i++)
    {
        this->targetVariable->markEvaluated();
        if(this->appliedOperators.at(i)->eval())
        {
            this->targetVariable->value = true;
            return this->targetVariable->value;
        }
    }
    this->targetVariable->value = false;
    return this->targetVariable->value;
}

bool LogicGraphNode::isEvaluated() {
    return this->targetVariable->isEvaluated();
}

const std::string &LogicGraphNode::getVarName() {
    return this->targetVariable->GetName();
}
