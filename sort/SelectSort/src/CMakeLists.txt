include_directories(../include)

aux_source_directory(./ SRC)

add_executable(SelectSort ${SRC})
