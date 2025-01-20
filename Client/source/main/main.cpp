#include <iostream>
#include <list>
#include <memory>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <main/game_structure.h>

int main(void)
{
    GameStructure game;
    game.circle();
    return 0;
}