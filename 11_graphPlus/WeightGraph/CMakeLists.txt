project(WeightGraph)

set(CMAKE_BUILD_TYPE Debug)

include_directories(../../03_linearList/MyQueue ../../07_priorityQueue/IndexPriorityQueue/Min ../../07_priorityQueue/MinPriorityQueue ../../09_UF/UF_Tree_Weighted)

aux_source_directory(. SRC)

add_executable(WeightGraph ${SRC})
