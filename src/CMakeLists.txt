cmake_minimum_required(VERSION 3.18.0)

#Libs for building test project
add_library(Server ./Server.cpp)
add_library(Client ./Client.cpp)
add_library(TCP ./TCPConnection.cpp)