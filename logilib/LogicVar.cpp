#include "LogicVar.h"

LogicVar::LogicVar(const std::string& _name) {
    this->name = _name;
    this->value = false;
    this->evaluated = false;
}

const std::string& LogicVar::GetName() {
    return this->name;
}

void LogicVar::markEvaluated() {
    this->evaluated = true;
}

bool LogicVar::isEvaluated() {
    return this->evaluated;
}

bool LogicVar::operator==(const LogicVar &other) {
    return this->name == other.name;
}

bool LogicVar::operator!=(const LogicVar &other) {
    return this->name != other.name;
}
