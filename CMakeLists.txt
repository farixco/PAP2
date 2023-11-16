cmake_minimum_required(VERSION 3.15)
project("Respaldo de CD")

add_compile_options(
       -Wall
       $<$<CONFIG:RELEASE>:-Ofast>
       $<$<CONFIG:DEBUG>:-O0>
       $<$<CONFIG:DEBUG>:-g>
)

enable_testing()
add_subdirectory(test)

add_executable(repcd src/main.cpp src/CD.cpp src/Queue.cpp)
