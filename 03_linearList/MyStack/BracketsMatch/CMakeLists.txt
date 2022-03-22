project(BracketsMatch)

include_directories(../)

set(CMAKE_BUILD_TYPE Debug)

aux_source_directory(. SRC)

add_executable(BracketsMatch ${SRC})
