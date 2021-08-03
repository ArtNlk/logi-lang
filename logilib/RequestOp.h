#ifndef LOGILANG_REQUESTOP_H
#define LOGILANG_REQUESTOP_H

#include "Operator.h"

class RequestOp : private Operator {
public:
    bool value;

    bool eval() override;
    void askUser();
};


#endif //LOGILANG_REQUESTOP_H
