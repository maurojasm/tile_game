# Binary File
OBJ := tile_game

# Source Files
SRC_DIR := src/
SOURCE_FILES := $(wildcard $(SRC_DIR)*.cpp)

# Source Objects
OBJ_DIR := bin/
# OBJECT_FILES := $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SOURCE_FILES))
OBJECT_FILES = ${SOURCE_FILES:.cpp=.o}

# Header Files
HEADER_DIR := include/

# Include directories
INCLUDE := -I$(HEADER_DIR)

CC := g++
CFLAGS := -Wall

LIBRARY := -F/Library/Frameworks -framework SDL2 -F/Library/Frameworks -framework SDL2_image

$(OBJ): $(OBJECT_FILES)
	@echo compiling binary \'$(OBJ)\'
	$(CC) $(LIBRARY) $(OBJECT_FILES) -o $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< $(CFLAGS) $(INCLUDE) -o $@