project(CityRoadTest)

set(CMAKE_BUILD_TYPE Debug)

include_directories(../UF_Tree_Weighted)

aux_source_directory(. SRC)

add_executable(CityRoadTest ${SRC})
