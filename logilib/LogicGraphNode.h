#ifndef LOGILANG_LOGICGRAPHNODE_H
#define LOGILANG_LOGICGRAPHNODE_H

#include <vector>
#include <stdexcept>
#include <string>

#include "LogicVar.h"
#include "operators.h"

enum DFSStatus {DFS_NOT_VISITED, DFS_IN_STACK, DFS_DONE};

class LogicGraphNode {
private:
    LogicVar* targetVariable;
    std::vector<Operator*> appliedOperators;
    DFSStatus status;
public:
    explicit LogicGraphNode(const std::string& varName);
    ~LogicGraphNode();

    void addOperator(Operator* newOp);
    bool eval();
    bool isEvaluated();
    const std::string& getVarName();
    DFSStatus getDFSStatus();
    void DFSmarkInStack();
    void DFSmarkDone();
    std::vector<LogicGraphNode*> getAdjacentNodes();
};


#endif //LOGILANG_LOGICGRAPHNODE_H
