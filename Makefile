# Compiler Setup
CXX=clang++
CXXFLAGS= -g -Wall -O0 -Wextra -std=c++17

# Source & Object files
SRC= src/sev.cpp
OBJ= Server.o TCPConnection.o Client.o 
LIB= lib/TCPConnection.cpp lib/Server.cpp lib/Client.cpp
DEP= include/Server.hpp include/TCPConnection.hpp lib/Client.hpp


Server: src/sev.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o svr 
Client: src/clnt.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o clnt
libs: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ 

$(OBJ): $(LIB)
	$(CXX) $(CXXFLAGS) -c $^ 

clean:
	$(RM) *.o svr clnt
