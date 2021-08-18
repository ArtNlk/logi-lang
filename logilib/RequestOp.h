#ifndef LOGILANG_REQUESTOP_H
#define LOGILANG_REQUESTOP_H

#include <iostream>
#include <limits>
#include <regex>
#include <cstdlib>

#include "Operator.h"

class RequestOp : public Operator {
public:
    static std::string operatorName;
private:
    std::string requestedVarName;

public:
    explicit RequestOp(const std::string& requestedVarName);
    bool eval() override;
    //static bool foundInCommandString(const std::string& targetString) override;
private:
    std::vector<LogicGraphNode*> getRequiredNodes() override;
    void addRequiredNode(LogicGraphNode* addedGraphNode) override;

};


#endif //LOGILANG_REQUESTOP_H
