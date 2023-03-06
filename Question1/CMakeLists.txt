cmake_minimum_required(VERSION 3.24)
project(CA C)

set(CMAKE_C_STANDARD 11)

add_executable(CA main.c pig.c test_pig.c piglatin.c pig_header.h test_pig_header.h piglatin_header.h)
