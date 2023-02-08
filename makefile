CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -fconcepts

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= src/options/*.cpp
EXECUTABLE	:= main

#  -lcurl -lzip
# In gh codespaces, use -std=c++17
# And remove -lcurl and -lzip from compiler

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
