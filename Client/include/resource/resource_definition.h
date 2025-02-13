#pragma once

#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <util/util_vector.h>

//TODO: 添加按钮图组(非连续动画，只存储开关两种状态)

/**
* @class ImageArea
* @brief 帧图位置及尺寸
**/
struct ImageArea 
{
    // 帧图起始位置
    UtilVector<int> pos;
    // 帧尺寸
    UtilVector<int> size;
    /**
    * @brief 将帧图位置及尺寸转换为SDL_Rect
    * @return SDL_Rect
    **/
    SDL_Rect to_rect()
    {
        return{ pos.x,pos.y,size.x,size.y };
    }
};

/**
* @class FrameInfo
* @brief 帧图信息
**/
struct FrameInfo 
{
    // 帧图名
    std::string filename;
    // 帧图位置及尺寸
    ImageArea frame;
    // 旋转
    bool rotated;
    // 裁剪
    bool trimmed;
    // 帧尺寸
    ImageArea spriteSourceSize;
    // 源尺寸
    UtilVector<int> sourceSize; 
};

/**
* @class Meta
* @brief 元信息
**/
struct Meta {
    // 工具
    std::string app;
    // 版本
    std::string version; 
    // 图片名
    std::string image;
    // 图片格式
    std::string format;
    // 图片尺寸
    ImageArea size;
    // 缩放
    std::string scale;
};

/**
* @class SpriteSheet
* @brief 精灵图帧图信息
**/
struct SpriteSheet
{
    SpriteSheet() = default;
    // 帧图信息列表
    std::vector<FrameInfo> frames;
    // 元信息
    Meta meta;
};

/**
* @class TextureInfo
* @brief 纹理信息
**/
struct TextureInfo
{
    // 纹理指针
    SDL_Texture* texture;
    // 纹理源帧图位置及尺寸
    ImageArea src;
    // 目标帧图位置及尺寸
    ImageArea dst;
};

/**
* @class SurfaceInfo
* @brief 表面信息
**/
struct SurfaceInfo
{
    // 表面指针
    SDL_Surface* surface;
    // 纹理源帧图位置及尺寸
    ImageArea src;
    // 目标帧图位置及尺寸
    ImageArea dst;
};

/**
* @class ButtonImageSet
* @brief 按钮图组，存储开关两种状态纹理
**/
struct ButtonImageSet
{
    // 普通状态纹理指针
    TextureInfo* normal;
    // 按下状态纹理指针
    TextureInfo* pressed;
};

/**
* @class AtlasFrame
* @brief 纹理帧
**/
struct AtlasFrame
{
    // 纹理信息
    TextureInfo texture;
    // 纹理序号
    int index;
};

