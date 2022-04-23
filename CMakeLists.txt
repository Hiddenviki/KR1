cmake_minimum_required(VERSION 3.20)
project(kr1)

set(CMAKE_CXX_STANDARD 17)

add_executable(kr1 main.cpp Point.h Circle.cpp Circle.h Point.cpp Circle_box.h StreamTable.h)
