cmake_minimum_required(VERSION 3.24)
project(Q3 C)

set(CMAKE_C_STANDARD 11)

add_executable(Q3 main.c main.c beggar.c single.h single.c byn.h byn.c shuffle.c shuffle.h)
