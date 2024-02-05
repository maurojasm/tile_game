/*
This source code copyrighted by Lazy Foo' Productions 2004-2024
*/

#pragma once

//Using SDL, SDL_image, standard IO, strings, and file streams
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>

#include "texture.h"

//The tile
class Tile
{
    public:
		//Tile constants
		const int TILE_WIDTH = 80;
		const int TILE_HEIGHT = 80;

		//Initializes position and type
		Tile( int x, int y, int tileType );

		//Shows the tile
		void render( SDL_Rect& camera, LTexture gTileTexture, SDL_Rect gTileClips[], SDL_Renderer *gRenderer );

		//Get the tile type
		int getType();

		//Get the collision box
		SDL_Rect getBox();

		//Box collision detector
		bool checkCollision( SDL_Rect a, SDL_Rect b );

    private:
		//The attributes of the tile
		SDL_Rect mBox;

		//The tile type
		int mType;
};