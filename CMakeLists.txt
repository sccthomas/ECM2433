cmake_minimum_required(VERSION 3.24)
project(CA C)

set(CMAKE_C_STANDARD 11)

add_executable(CA Question1/main.c Question1/pig.c Question1/test_pig.c Question1/piglatin.c Question1/pig_header.h Question1/test_pig_header.h Question1/piglatin_header.h Question2/riffle.c Question2/demo_shuffle.h Question2/demo_shuffle.c Question2/quality.h Question2/quality.c Question3/beggar.c Question3/beggar.h)
