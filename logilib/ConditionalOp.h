#ifndef LOGILANG_CONDITIONALOP_H
#define LOGILANG_CONDITIONALOP_H

#include <vector>

#include "Operator.h"

class LogicGraphNode;//Prevent circular include, forward declare it

class ConditionalOp : public Operator {
public:
    static std::string operatorString;
private:
    std::vector<LogicGraphNode*> requiredNodes;

public:
    explicit ConditionalOp(const std::vector<LogicGraphNode*>& _requiredNodes);
    explicit ConditionalOp();
    void addRequiredNode(LogicGraphNode* requiredNode);
    bool eval() override;
};


#endif //LOGILANG_CONDITIONALOP_H
