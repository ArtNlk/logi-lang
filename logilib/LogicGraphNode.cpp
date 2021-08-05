#include "LogicGraphNode.h"

LogicGraphNode::LogicGraphNode(LogicVar* targetLogicVar) {
    if(targetLogicVar == nullptr)
    {
        throw std::invalid_argument("Logic graph node: target variable ptr is NULL");
    }
    this->targetVariable = targetLogicVar;
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
