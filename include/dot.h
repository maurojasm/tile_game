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

#include "tile.h"
#include "texture.h"

//The dot that will move around on the screen
class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//The dimensions of the level
		const int LEVEL_WIDTH = 1280;
		const int LEVEL_HEIGHT = 960;

		//Screen dimension constants
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;

		//Tile constants
		const int TILE_WIDTH = 80;
		const int TILE_HEIGHT = 80;
		const int TOTAL_TILES = 192;
		const int TOTAL_TILE_SPRITES = 12;
		
		//The different tile sprites
		const int TILE_RED = 0;
		const int TILE_GREEN = 1;
		const int TILE_BLUE = 2;
		const int TILE_CENTER = 3;
		const int TILE_TOP = 4;
		const int TILE_TOPRIGHT = 5;
		const int TILE_RIGHT = 6;
		const int TILE_BOTTOMRIGHT = 7;
		const int TILE_BOTTOM = 8;
		const int TILE_BOTTOMLEFT = 9;
		const int TILE_LEFT = 10;
		const int TILE_TOPLEFT = 11;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot and check collision against tiles
		void move( Tile *tiles[] );

		//Checks collision box against set of tiles
		bool touchesWall( SDL_Rect box, Tile* tiles[] );

		//Box collision detector
		bool checkCollision( SDL_Rect a, SDL_Rect b );

		//Centers the camera over the dot
		void setCamera( SDL_Rect& camera );

		//Shows the dot on the screen
		void render( LTexture gDotTexture, SDL_Rect& camera, SDL_Renderer* gRenderer );

    private:
		//Collision box of the dot
		SDL_Rect mBox;

		//The velocity of the dot
		int mVelX, mVelY;
};