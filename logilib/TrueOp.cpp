#include "TrueOp.h"
std::string TrueOp::operatorString = "true";

TrueOp::TrueOp() {
    this->value = true;
    this->evaluated = false;
}

bool TrueOp::eval() {
    this->evaluated = true;
    return true;
}
