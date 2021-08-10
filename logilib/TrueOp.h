#ifndef LOGILANG_TRUEOP_H
#define LOGILANG_TRUEOP_H

#include <string>
#include <regex>

#include "Operator.h"

class TrueOp : public Operator {
public:
    TrueOp();
    static std::string operatorRegex;

    bool eval() override;
    static bool foundInCommandString(const std::string& targetString) override;
private:
    std::vector<LogicGraphNode*> getRequiredNodes() override;
    void addRequiredNode(LogicGraphNode* addedGraphNode) override;
};


#endif //LOGILANG_TRUEOP_H
