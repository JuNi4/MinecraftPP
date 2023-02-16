CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -fconcepts

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= include/comms/comms.cpp include/sounds/sound.cpp -lzip -lcurl -lsfml-audio
EXECUTABLE	:= main

#  -lcurl -lzip
# In gh codespaces, use -std=c++17

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
