cmake_minimum_required(VERSION 3.5)
project(Pucker CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE pacmain.cpp)

# add librarys
include_directories(inc)
include_directories(src)


# create unittests
add_executable(pucker ${SOURCE})


