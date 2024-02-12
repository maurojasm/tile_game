/*This source code copyrighted by Lazy Foo' Productions 2004-2024*/

#pragma once

//Using SDL, SDL_image, standard IO, strings, and file streams
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>

#include "../include/dot.h"
#include "../include/tile.h"
#include "../include/texture.h"

class App {
    public:
        //Screen dimension constants
        const int SCREEN_WIDTH = 640;
        const int SCREEN_HEIGHT = 480;

        //The dimensions of the level
        const int LEVEL_WIDTH = 1280;
        const int LEVEL_HEIGHT = 960;

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

        //Starts up SDL and creates window
        bool init();

        //Loads media
        bool loadMedia( Tile* tiles[] );

        //Frees media and shuts down SDL
        void close( Tile* tiles[] );

        //Box collision detector
        // bool checkCollision( SDL_Rect a, SDL_Rect b );

        // //Checks collision box against set of tiles
        // bool touchesWall( SDL_Rect box, Tile* tiles[] );

        //Sets tiles from tile map
        bool setTiles( Tile *tiles[] );

        void start();
    private:
        //The window we'll be rendering to
        SDL_Window* gWindow = NULL;

        //The window renderer
        SDL_Renderer* gRenderer = NULL;

        //Scene textures
        LTexture gDotTexture;
        LTexture gTileTexture;
        SDL_Rect gTileClips[ 12 ];
};