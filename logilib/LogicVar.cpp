#include "LogicVar.h"

void LogicVar::SetName(const std::string &newName) {
    this->name = newName;
}

std::string LogicVar::GetName() {
    return this->name;
}

void LogicVar::markEvaluated() {
    this->evaluated = true;
}

bool LogicVar::isEvaluated() {
    return this->evaluated;
}
