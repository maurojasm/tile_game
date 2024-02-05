# Compiler
CC = g++

# Binary file
OBJ = tile_game

# Headers directory
HEADER_DIR = ../include/

# Include command
INCLUDE = -I$(HEADER_DIR)

# Source Objects
# OBJ_DIR := bin/
OBJECT_FILES = main.o dot.o texture.o tile.o 

# Flags
CFLAGS := -Wall -std=c++11

# Linking Library
LINK_LIB = -F /Library/Frameworks -framework SDL2 -F /Library/Frameworks -framework SDL2_image
LIBRARY := -F /Library/Frameworks

# Instantly runs the game after linking
run: $(OBJ)
	./$(OBJ)

$(OBJ): $(OBJECT_FILES)
	@echo "\nLinking..."
	$(CC) $(CFLAGS) $(LINK_LIB) -o $(OBJ) $(OBJECT_FILES)
	@echo "Linking for target $(OBJ) succeeded!\n"

main.o: main.cpp $(HEADER_DIR)dot.h $(HEADER_DIR)texture.h $(HEADER_DIR)tile.h 
	@echo "Compiling:"
	$(CC) $(CFLAGS) $(LIBRARY) -c main.cpp

dot.o: dot.cpp $(HEADER_DIR)dot.h $(HEADER_DIR)texture.h
	@echo "\nCompiling:"
	$(CC) $(CFLAGS) $(LIBRARY) -c dot.cpp

texture.o: texture.cpp $(HEADER_DIR)texture.h
	@echo "\nCompiling:"
	$(CC) $(CFLAGS) $(LIBRARY) -c texture.cpp

tile.o: tile.cpp $(HEADER_DIR)tile.h
	@echo "\nCompiling:"
	$(CC) $(CFLAGS) $(LIBRARY) -c tile.cpp

.PHONY: clean

clean:
	rm -f *.o *~ $(OBJ) $(HEADER_DIR)/*~ 