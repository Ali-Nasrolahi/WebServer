# Compiler Setup
CXX=clang++
CXXFLAGS= -Wall -O2 -Wextra -std=c++17

# Source & Object files
SRC= src/sample.cpp
OBJ= Server.o TCPConnection.o sample.o
LIB= lib/TCPConnection.cpp lib/Server.cpp
DEP= include/Server.hpp include/TCPConnection.hpp

all: sample

sample: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o sample

$(OBJ) : $(LIB) $(DEP) $(SRC)
	$(CXX) $(CXXFLAGS) -c $^

clean:
	$(RM) $(OBJ) sample