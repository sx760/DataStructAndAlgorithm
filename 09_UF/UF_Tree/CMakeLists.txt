project(UFTreeTest)

set(CMAKE_BUILD_TYPE Debug)

aux_source_directory(. SRC)

add_executable(UFTreeTest ${SRC})
