#ifndef LOGILANG_LOGICVAR_H
#define LOGILANG_LOGICVAR_H

#include <cstdlib>
#include <string>
#include <vector>

class LogicVar {
public:
    bool value;
private:
    std::string name;
    bool evaluated;

public:
    explicit LogicVar(const std::string& _name);
    std::string GetName();
    void markEvaluated();
    bool isEvaluated();
    bool operator ==(const LogicVar& other);
    bool operator !=(const LogicVar& other);
};


#endif //LOGILANG_LOGICVAR_H
