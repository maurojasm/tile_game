# Binary File
OBJ := tile_game

# Source Files
SRC_DIR := src/
SOURCE_FILES := $(wildcard $(SRC_DIR)*.cpp)

# Source Objects
OBJ_DIR := bin/
# OBJECT_FILES := $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SOURCE_FILES))
OBJECT_FILES = $(addprefix $(OBJ_DIR),$(notdir $(SOURCES:.cpp=.o)))

# Header Files
HEADER_DIR := include/

# Include directories
INCLUDE := -I$(HEADER_DIR)

CC := g++
CFLAGS := -Wall -std=c++11 -I /Library/Frameworks/SDL2.framework/Headers -I /Library/Frameworks/SDL2_image.framework/Headers

LIBRARY := -F/Library/Frameworks -framework SDL2 -F/Library/Frameworks -framework SDL2_image
# LIBRARY := -F /Library/Frameworks -framework SDL2 -I /Library/Frameworks/SDL2.framework/Headers -F /Library/Frameworks -framework SDL2_image -I /Library/Frameworks/SDL2_image.framework/Headers

# CFLAGS:= -c -Wall -Wmissing-prototypes -Wstrict-prototypes -O2 -isystem /usr/local/include/SDL2 -Iinclude
# LDFLAGS:= -L/usr/local/lib
# LDLIBS:= -lSDL2 -lSDL2_image

# Instantly runs the game after linking
run: $(OBJ)
	./$(OBJ)

$(OBJ): $(OBJECT_FILES)
	@echo "Linking..."
	$(CC) $(OBJECT_FILES) -o $(OBJ) $(LIBRARY)
	@echo "Linking for target $(OBJ) succeeded!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "Compiling:"
	$(CC) -c $< $(CFLAGS) $(INCLUDE) -o $@