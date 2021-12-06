cmake_minimum_required(VERSION 3.18.0)

project(Weby)
set(CMAKE_CXX_COMPILER "g++")

add_library(client STATIC ./src/Client.cpp)