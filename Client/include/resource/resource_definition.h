#pragma once

#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <util/util_vector.h>

struct ImageArea {
    UtilVector<int> pos;// 帧图起始位置
    UtilVector<int> size;// 帧尺寸
};

struct FrameInfo {
    std::string filename;// 帧图名
    ImageArea frame;// 帧图位置及尺寸
    bool rotated;
    bool trimmed;
    ImageArea spriteSourceSize;// 帧尺寸
    UtilVector<int> sourceSize; // 帧尺寸
};

struct Meta {
    std::string app;// 工具
    std::string version; // 版本
    std::string image;// 图片名
    std::string format;// 图片格式
    ImageArea size;// 图片尺寸
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
    ImageArea src;// 帧图位置及尺寸
    ImageArea dst;// 目标帧图位置及尺寸
};

struct SurfaceInfo
{
    SDL_Surface* surface;
    ImageArea src;
    ImageArea dst;
};

