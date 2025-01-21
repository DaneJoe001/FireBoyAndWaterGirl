#pragma once

#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <util/util_vector.h>

struct ImageArea {
    UtilVector pos;
    UtilVector size;
};

struct FrameInfo {
    std::string filename;
    ImageArea frame;
    bool rotated;
    bool trimmed;
    ImageArea spriteSourceSize;
    UtilVector sourceSize;
};

struct Meta {
    std::string app;
    std::string version;
    std::string image;
    std::string format;
    ImageArea size;
    std::string scale;
};

struct SpriteSheet
{
    SpriteSheet() = default;
    std::vector<FrameInfo> frames;
    Meta meta;
};

struct TextureInfo
{
    SDL_Texture* texture;
    ImageArea src;
    ImageArea dst;
};

struct SurfaceInfo
{
    SDL_Surface* surface;
    ImageArea src;
    ImageArea dst;
};

