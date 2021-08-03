project(logilang)

set(SOURCES_LOGILIB LogicVar.cpp LogicVar.h Operator.cpp Operator.h RequestOp.cpp RequestOp.h TrueOp.cpp TrueOp.h TrueifOp.cpp TrueifOp.h operators.h LogicGraphNode.cpp LogicGraphNode.h)

add_library(logilib STATIC ${SOURCES_LOGILIB})