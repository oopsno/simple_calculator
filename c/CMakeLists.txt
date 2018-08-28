cmake_minimum_required(VERSION 3.10)
project(SimpleCalculator C)
set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

add_library(common common.c common.h)

add_executable(challenge-1 challenge-1.c)
target_link_libraries(challenge-1 common m)

add_executable(challenge-2-settler challenge-2-settler.c)
target_link_libraries(challenge-2-settler common m)

add_executable(challenge-2-deity challenge-2-deity.c)
target_link_libraries(challenge-2-deity common m)
