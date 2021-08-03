#ifndef LOGILANG_TRUEIFOP_H
#define LOGILANG_TRUEIFOP_H

#include <vector>

#include "Operator.h"

class LogicGraphNode;//Prevent circular include, forward declare it

class TrueifOp : private Operator {
private:
    std::vector<LogicGraphNode> linkedNodes;

public:
    bool eval() override;
};


#endif //LOGILANG_TRUEIFOP_H
