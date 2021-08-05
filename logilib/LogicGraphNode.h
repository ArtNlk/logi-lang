#ifndef LOGILANG_LOGICGRAPHNODE_H
#define LOGILANG_LOGICGRAPHNODE_H

#include <vector>
#include <stdexcept>

#include "LogicVar.h"
#include "operators.h"

class LogicGraphNode {
private:
    LogicVar* targetVariable;
    std::vector<Operator*> appliedOperators;
public:
    explicit LogicGraphNode(LogicVar* targetLogicVar);
    ~LogicGraphNode() = default;
    void addOperator(Operator* newOp);
    bool eval();
    bool isEvaluated();
};


#endif //LOGILANG_LOGICGRAPHNODE_H
