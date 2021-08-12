#include "TrueOp.h"
std::string TrueOp::operatorName = "true";

TrueOp::TrueOp() {
    this->value = true;
    this->evaluated = false;
}

bool TrueOp::eval() {
    this->evaluated = true;
    return true;
}

bool TrueOp::foundInCommandString(const std::string& targetString) {
    auto regex = std::regex(TrueOp::operatorName);
    return std::regex_match(targetString,regex);
}

std::vector<LogicGraphNode*> TrueOp::getRequiredNodes() {
    return std::vector<LogicGraphNode *>();
}

void TrueOp::addRequiredNode(LogicGraphNode* addedGraphNode) {

}
