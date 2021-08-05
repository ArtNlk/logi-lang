#ifndef LOGILANG_TRUEOP_H
#define LOGILANG_TRUEOP_H

#include <string>

#include "Operator.h"

class TrueOp : public Operator {
public:
    TrueOp();
    static std::string operatorString;
    bool eval() override;
};


#endif //LOGILANG_TRUEOP_H
