project(test)

set(CMAKE_BUILD_TYPE Debug)

include_directories(../03_linearList/MyQueue)

aux_source_directory(. SRC)

add_executable(test ${SRC})
