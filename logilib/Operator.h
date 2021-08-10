#ifndef LOGILANG_OPERATOR_H
#define LOGILANG_OPERATOR_H

#include <string>
#include <vector>

class LogicGraphNode;//Prevent circular include, forward declare it

enum operatorType {INVALID_OP,TRUE_OP,REQUEST_OP,CONDITIONAL_OP};

class Operator {
public:
    bool value;
    bool evaluated;

public:
    virtual ~Operator() = default;
    virtual bool eval() = 0;
    virtual std::vector<LogicGraphNode*> getRequiredNodes() = 0;
    virtual void addRequiredNode(LogicGraphNode* addedGraphNode) = 0;
    //virtual static bool foundInCommandString(const std::string &targetString) = 0;
};


#endif //LOGILANG_OPERATOR_H
