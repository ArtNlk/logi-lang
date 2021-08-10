#include "ConditionalOp.h"
#include "LogicGraphNode.h"//Prevent circular include

std::string ConditionalOp::operatorRegex = "(conditional\\(((\\s*\\w+\\s*,)*(\\s*\\w+\\s*))\\))";


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

std::vector<LogicGraphNode *> ConditionalOp::getRequiredNodes() {
    return this->requiredNodes;
}

bool ConditionalOp::foundInCommandString(const std::string& targetString) {
    auto regex = std::regex(ConditionalOp::operatorRegex);
    return std::regex_match(targetString,regex);
}

std::vector<std::string> ConditionalOp::paramStringToVarNames(const std::string &paramString) {
    std::stringstream inputStringStream = std::stringstream(paramString);
    std::string segment;
    std::vector<std::string> seglist;

    while(std::getline(inputStringStream, segment, ','))
    {
        seglist.push_back(segment);
    }

    return seglist;
}
