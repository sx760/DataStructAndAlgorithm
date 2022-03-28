project(DirectedWeightGraph)

set(CMAKE_BUILD_TYPE Debug)

include_directories(../../03_linearList/MyQueue ../../07_priorityQueue/IndexPriorityQueue/Min)

aux_source_directory(. SRC)

add_executable(DirectedWeightGraph ${SRC})
