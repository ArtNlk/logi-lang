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
    void SetName(const std::string& newName);
    std::string GetName();
    void markEvaluated();
    bool isEvaluated();
};


#endif //LOGILANG_LOGICVAR_H
