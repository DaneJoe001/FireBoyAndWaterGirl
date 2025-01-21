#include <iostream>
#include <list>
#include <memory>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <main/game_structure.h>
#include <util/util_log.h>

int main(void)
{
    UtilLog::clear_log(LogLevel::DEVELOPPER);
    UtilLog::clear_log(LogLevel::USER);
    GameStructure game;
    game.circle();
    return 0;
}