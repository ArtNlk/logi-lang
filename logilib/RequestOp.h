#ifndef LOGILANG_REQUESTOP_H
#define LOGILANG_REQUESTOP_H

#include <iostream>
#include <limits>

#include "Operator.h"

class RequestOp : public Operator {
public:
    static std::string operatorString;
private:
    std::string requestedVarName;

public:
    explicit RequestOp(const std::string& requestedVarName);
    bool eval() override;
};


#endif //LOGILANG_REQUESTOP_H
