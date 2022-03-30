project(DP)

set(CMAKE_BUILD_TYPE Debug)

aux_source_directory(. SRC)

add_executable(DP ${SRC})
