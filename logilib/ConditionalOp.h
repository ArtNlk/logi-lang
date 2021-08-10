#ifndef LOGILANG_CONDITIONALOP_H
#define LOGILANG_CONDITIONALOP_H

#include <vector>
#include <regex>
#include <string>
#include <sstream>

#include "Operator.h"

class ConditionalOp : public Operator {
public:
    static std::string operatorRegex;
private:
    std::vector<LogicGraphNode*> requiredNodes;

public:
    explicit ConditionalOp(const std::vector<LogicGraphNode*>& _requiredNodes);
    explicit ConditionalOp();
    bool eval() override;
    static bool foundInCommandString(const std::string& targetString);
    std::vector<LogicGraphNode*> getRequiredNodes() override;
    void addRequiredNode(LogicGraphNode* addedGraphNode) override;
    static std::vector<std::string> paramStringToVarNames(const std::string& paramString);
};


#endif //LOGILANG_CONDITIONALOP_H
