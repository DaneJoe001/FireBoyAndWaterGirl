#pragma once

#include <memory>
#include <mutex>
#include <string>
#include <optional>
#include <filesystem>
#include <unordered_map>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <resource/resource_atlas.h>
#include <resource/resource_definition.h>
#include <util/util_vector.h>
#include <util/util_parse_sprite_sheet.h>

namespace fs = std::filesystem;

/**
* @class FileFormat
* @brief 文件格式枚举
**/
enum class FileFormat
{
    PNG=0,
    OGG=1,
    JSON=2,
    FNT=3,
    TTF=4,
};

/**
* @class FileLoadMode
* @brief 文件加载模式枚举
**/
enum class FileLoadMode
{
    // 未指定
    UNSPECIFIED=0,
    // 纹理
    TEXTURE = 1,
    // 表面
    SURFACE = 2,
    // 精灵图
    SPRITE_SHEET=3,
    // 配置文件
    CONFIGURATION=4,
};

//TODO:考虑直接遍历texture_info列表，将名称相同但序号不同的按照序号排列成帧图集

/**
* @class ManageResource
* @brief 资源管理类，在初始化renderer之后才能初始化资源
**/
class ManageResource
{
public:
    /**
    * @brief 获取资源管理类单例对象引用
    **/
    static ManageResource& get_instance();
    /**
    * @brief 加载资源。
    **/
    void load_resource();
    /**
    * @brief 初始化资源管理类，在初始化renderer之后才能初始化资源
    * @param renderer SDL渲染器
    **/
    static void init(SDL_Renderer* renderer);
    /**
    * @brief 设置窗口大小
    * @param size 窗口大小
    **/
    static void set_window_size(const UtilVector<int>& size);
    /**
    * @brief 获取窗口大小
    **/
    static UtilVector<int> get_window_size();
    /**
    * @brief 获取纹理
    * @param image_name 纹理名称
    **/
    SDL_Texture* get_texture(const std::string& image_name);
    /**
    * @brief 获取表面
    * @param image_name 表面名称
    **/
    SDL_Surface* get_surface(const std::string& image_name);
    /**
    * @brief 获取表面信息
    * @param image_name 表面名称
    **/
    SurfaceInfo* get_surface_info(const std::string& image_name);
    /**
    * @brief 获取纹理信息
    * @param image_name 纹理名称
    **/
    TextureInfo* get_texture_info(const std::string& image_name);
    /**
    * @brief 获取图集
    * @param atlas_name 图集名称
    **/
    ResourceAtlas* get_atlas(const std::string& atlas_name);
    /**
    * @brief 获取音乐
    * @param music_name 音乐名称
    **/
    Mix_Music* get_music(const std::string& music_name);
    /**
    * @brief 获取随机纹理,用于检查纹理加载状态
    **/
    TextureInfo* randon_get_texture();

private:
    ManageResource();
    /**
    * @brief 资源管理类析构函数，析构时释放资源
    **/
    ~ManageResource();
    ManageResource(const ManageResource&) = delete;
    ManageResource& operator=(const ManageResource&) = delete;
    ManageResource(ManageResource&&) = delete;
    ManageResource& operator=(ManageResource&&) = delete;
    /**
    * @brief 加载纹理，暂未实现
    * @param path_temp 纹理路径
    * @param num 纹理数量
    **/
    void load_altas(const std::string& path_temp, int num);
    /**
    * @brief 通过精灵图加载图集
    * @param info 精灵图信息
    **/
    void load_atlas(SpriteSheet& info);
    /**
    * @brief 加载纹理
    * @param image_name 纹理名称
    * @param path_temp 纹理路径
    **/
    void load_texture(const std::string& image_name, const std::string& path_temp);
    /**
    * @brief 加载表面
    * @param image_name 表面名称
    * @param path_temp 表面路径
    **/
    void load_surface(const std::string& image_name, const std::string& path_temp);
    /**
    * @brief 加载纹理信息
    * @param path 纹理路径
    * @param frame_info 纹理信息
    **/
    void load_texture_info(const std::string& path, FrameInfo& frame_info);
    /**
    * @brief 加载纹理信息
    * @param image_name 纹理名称
    * @param size 纹理尺寸
    **/
    void load_texture_info(const std::string& image_name,UtilVector<int> size);
    /**
    * @brief 加载纹理信息
    * @param texture 纹理
    * @param frame_info 纹理信息
    **/
    void load_texture_info(SDL_Texture* texture, FrameInfo& frame_info);
    /**
    * @brief 加载表面信息
    * @param path 表面路径
    * @param frame_info 表面信息
    **/
    void load_surface_info(const std::string& path, FrameInfo& frame_info);
    /**
    * @brief 加载精灵图
    * @param path 精灵图路径
    **/
    void load_sprite_sheet(const std::string& path);
    /**
    * @brief 加载音乐
    * @param music_name 音乐名称
    * @param path 音乐路径
    **/
    void load_music(const std::string& music_name, const std::string& path);
    /**
    * @brief 加载fnt字体
    * @param path 字体路径
    * @param font_name 字体名称
    **/
    void load_fnt(const std::string& path, const std::string& font_name);
    /**
    * @brief 加载ttf字体
    * @param path 字体路径
    * @param size 字体大小
    * @param font_name 字体名称
    **/
    void load_ttf(const std::string& path, std::size_t size, const std::string& font_name);
    /**
    * @brief 自动加载目录下的资源
    * @param path 目录路径
    * @param extension 文件格式
    * @param mode 加载模式
    **/
    void auto_load_directory_resource(const fs::path&, FileFormat extension,FileLoadMode mode);

private:
    // 互斥锁,保证线程安全
    static std::mutex m_mutex;
    // 渲染器
    static SDL_Renderer* m_renderer;
    //图集资源
    std::unordered_map<std::string, ResourceAtlas> m_resource_atlas_map;
    // 纹理指针资源
    std::unordered_map<std::string, SDL_Texture*> m_texture_map;
    // 表面指针资源
    std::unordered_map<std::string, SDL_Surface*> m_surface_map;
    // 纹理信息资源
    std::unordered_map<std::string, TextureInfo> m_texture_info_map;
    // 表面信息资源
    std::unordered_map<std::string, SurfaceInfo> m_surface_info_map;
    // 精灵图资源
    std::unordered_map<std::string, SpriteSheet>m_sprite_sheet_map;
    // 窗口大小
    static UtilVector<int> m_window_size;
    // 音乐资源
    std::unordered_map<std::string, Mix_Music*> m_music_map;
    // fnt字体资源
    std::unordered_map<std::string, std::unordered_map<char,TextureInfo>> m_fnt_font_map;
    // ttf字体资源
    std::unordered_map<std::string, TTF_Font*> m_ttf_font_map;

};