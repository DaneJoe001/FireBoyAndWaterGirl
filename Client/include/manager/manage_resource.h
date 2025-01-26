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

enum class FileFormat
{
    PNG=0,
    OGG=1,
    JSON=2,
};

enum class FileLoadMode
{
    UNSPECIFIED=0,
    TEXTURE = 1,
    SURFACE = 2,
    SPRITE_SHEET=3,
    CONFIGURATION=4,
};

class ManageResource
{
public:
    static ManageResource& get_instance();
    //在初始化renderer之后才能初始化资源
    void load_resource();
    static void init(SDL_Renderer* renderer);
    static void set_window_size(const UtilVector<int>& size);
    static UtilVector<int> get_window_size();
    SDL_Texture* get_texture(const std::string& image_name);
    SDL_Surface* get_surface(const std::string& image_name);
    SurfaceInfo& get_surface_info(const std::string& image_name);
    TextureInfo& get_texture_info(const std::string& image_name);
    Mix_Music* get_music(const std::string& music_name);
    //遍历素材，用于检查
    TextureInfo& randon_get_texture();
private:
    ManageResource();
    ~ManageResource();
    ManageResource(const ManageResource&) = delete;
    ManageResource& operator=(const ManageResource&) = delete;
    ManageResource(ManageResource&&) = delete;
    ManageResource& operator=(ManageResource&&) = delete;
    //TODO:考虑直接遍历texture_info列表，将名称相同但序号不同的按照序号排列成帧图集
    void load_altas(const std::string& path_temp, int num);
    void load_atlas(SpriteSheet& info);
    void load_texture(const std::string& image_name, const std::string& path_temp);
    void load_surface(const std::string& image_name, const std::string& path_temp);
    void load_texture_info(const std::string& path, FrameInfo& frame_info);
    void load_texture_info(SDL_Texture* texture, FrameInfo& frame_info);
    void load_surface_info(const std::string& path, FrameInfo& frame_info);
    // 从精灵图到序列帧图集
    void load_sprite_sheet(const std::string& path);
    void load_music(const std::string& music_name, const std::string& path);
    void auto_load_directory_resource(const fs::path&, FileFormat extension,FileLoadMode mode);

private:
    static std::mutex m_mutex;
    static SDL_Renderer* m_renderer;
    std::unordered_map<std::string, ResourceAtlas> m_resource_atlas_map;
    //texture和surface的映射用于存放纹理和表面信息
    //texture_info 和 surface_info 的映射用于存放实际帧信息
    std::unordered_map<std::string, SDL_Texture*> m_texture_map;
    std::unordered_map<std::string, SDL_Surface*> m_surface_map;
    // texture_info 和 surface_info 的映射用于存放对应图片池中的图片引用和位置尺寸信息
    std::unordered_map<std::string, TextureInfo> m_texture_info_map;
    std::unordered_map<std::string, SurfaceInfo> m_surface_info_map;
    std::unordered_map<std::string, SpriteSheet>m_sprite_sheet_map;
    static UtilVector<int> m_window_size;
    std::unordered_map<std::string, Mix_Music*> m_music_map;


};