# 有向图
project(GraphTest)

set(CMAKE_BUILD_TYPE Debug)

include_directories(../../03_linearList/MyQueue ../../03_linearList/MyStack)

aux_source_directory(. SRC)

add_executable(GraphTest ${SRC})
