cmake_minimum_required(VERSION 3.18.0)

project(Weby)

#Set Compiler Properties
set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_CXX_FLAGS_DEBUG "-g")

#Set Static Libs properties
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

#Executable dir settings
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#Libs needed for building test files
add_subdirectory(src)

#Test files
add_executable(Svr ./test/sev.cpp)
add_executable(Clnt ./test/clnt.cpp)

#Linking Libs to Executable
target_link_libraries(Svr Server TCP)
target_link_libraries(Clnt Client Server TCP)

