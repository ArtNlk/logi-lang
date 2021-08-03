project(logilang)

set(SOURCES_LOGILANG main.cpp)

include_directories(../logilib)

add_executable(logilang ${SOURCES_LOGILANG})

target_link_libraries(logilang logilib)