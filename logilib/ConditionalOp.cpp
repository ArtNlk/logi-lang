#include "ConditionalOp.h"
#include "LogicGraphNode.h"//Prevent circular include

std::string ConditionalOp::operatorString = "conditional";


ConditionalOp::ConditionalOp() {
    this->evaluated = false;
    this->value = false;
}

ConditionalOp::ConditionalOp(const std::vector<LogicGraphNode*>& _requiredNodes) {
    this->requiredNodes = _requiredNodes;
    this->evaluated = false;
    this->value = false;
}

void ConditionalOp::addRequiredNode(LogicGraphNode* requiredNode) {
    this->requiredNodes.push_back(requiredNode);
}

bool ConditionalOp::eval() {
    if(this->evaluated)
    {
        return this->value;
    }

    this->evaluated = true;

    for(int i = 0; i < this->requiredNodes.size(); i++)
    {
        if(!this->requiredNodes.at(i)->eval())
        {
            this->value = false;
        }
    }
    this->value = true;

    return this->value;
}
