#ifndef LOGILANG_TRUEOP_H
#define LOGILANG_TRUEOP_H

#include "Operator.h"

class TrueOp : private Operator {
public:
    bool eval() override;
};


#endif //LOGILANG_TRUEOP_H
