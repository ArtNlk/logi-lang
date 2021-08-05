#ifndef LOGILANG_OPERATOR_H
#define LOGILANG_OPERATOR_H

#include <string>

class Operator {
public:
    bool value;
    bool evaluated;
    virtual bool eval() = 0;
    virtual ~Operator() = default;
};


#endif //LOGILANG_OPERATOR_H
