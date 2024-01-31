IDIR = include/
SRCDIR = src/
CC = g++
CFLAGS = -Wall -I$(IDIR) -F/Library/Frameworks -framework SDL2 -F/Library/Frameworks -framework SDL2_image
ODIR = bin/

_DEPS := dot.h texture.h tile.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ := tile_game.o dot.o texture.o tile.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tile_game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 