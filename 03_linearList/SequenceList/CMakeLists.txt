cmake_minimum_required(VERSION 3.0)

project(SequenceList)

set(CMAKE_BUILD_TYPE Debug)

aux_source_directory(. SRC)

add_executable(SequenceList SRC)