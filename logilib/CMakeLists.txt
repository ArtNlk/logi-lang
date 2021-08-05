project(logilang)

set(SOURCES_LOGILIB LogicVar.cpp LogicVar.h Operator.cpp Operator.h RequestOp.cpp RequestOp.h TrueOp.cpp TrueOp.h ConditionalOp.cpp ConditionalOp.h operators.h LogicGraphNode.cpp LogicGraphNode.h LogiSolver.cpp LogiSolver.h)

add_library(logilib STATIC ${SOURCES_LOGILIB})