cmake_minimum_required(VERSION 3.0)

project(Test)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g2 -ggdb")

set(CMAKE_CXX_fLAGS_RELEASE "-Wall -O3")

set(CXX_STANDARD 11)

add_subdirectory(13_trieTree)
