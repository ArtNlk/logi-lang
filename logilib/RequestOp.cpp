#include "RequestOp.h"

std::string RequestOp::operatorString = "conditional";

RequestOp::RequestOp(const std::string& _requestedVarName) {
    this->requestedVarName = _requestedVarName;
    this->evaluated = false;
    this->value = false;
}

bool RequestOp::eval() {
    if(this->evaluated)
    {
        return this->value;
    }
    do
    {
        std::cout << "Enter " << this->requestedVarName << " value (true/false)\n";
        if (std::cin >> std::boolalpha >> this->value)
            break;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Error! Input value is not boolean! Try again:\n";
    } while(true);

    this->evaluated = true;

    return this->value;
}
