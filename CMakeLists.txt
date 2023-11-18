cmake_minimum_required(VERSION 3.15)
set (CMAKE_CXX_STANDARD 17)
project("InMemoryDB")

add_compile_options(
       -Wall
       $<$<CONFIG:RELEASE>:-Ofast>
       $<$<CONFIG:DEBUG>:-O0>
       $<$<CONFIG:DEBUG>:-g>
)

# enable_testing()
# add_subdirectory(test)

add_executable(memdb src/main.cpp src/DB.cpp src/Hash.cpp)
