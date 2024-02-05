CC = g++
OBJ = tile_game

HEADER_DIR = ../include/
INCLUDE = -I$(HEADER_DIR)

OBJECT_FILES = main.o dot.o texture.o tile.o 

CFLAGS := -Wall -std=c++11 -I /Library/Frameworks/SDL2.framework/Headers -I /Library/Frameworks/SDL2_image.framework/Headers

LIBRARY := -F /Library/Frameworks -framework SDL2 -I /Library/Frameworks/SDL2.framework/Headers -F /Library/Frameworks -framework SDL2_image -I /Library/Frameworks/SDL2_image.framework/Headers

$(OBJ): $(OBJECT_FILES)
	@echo "Linking..."
	$(CC) $(CFLAGS) $(LIBRARY) -o $(OBJ) $(OBJECT_FILES)
	@echo "Linking for target $(OBJ) succeeded!"

main.o: main.cpp $(HEADER_DIR)dot.h $(HEADER_DIR)texture.h $(HEADER_DIR)tile.h 
	@echo "\nCompiling:"
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
	rm -f *.o *~ core $(HEADER_DIR)/*~ 