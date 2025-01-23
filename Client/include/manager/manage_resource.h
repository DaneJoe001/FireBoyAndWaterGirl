#pragma once

#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <resource/resource_atlas.h>
#include <resource/resource_definition.h>
#include <util/util_vector.h>
#include <util/util_parse_sprite_sheet.h>

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
private:
    ManageResource();
    ~ManageResource();
    ManageResource(const ManageResource&) = delete;
    ManageResource& operator=(const ManageResource&) = delete;
    ManageResource(ManageResource&&) = delete;
    ManageResource& operator=(ManageResource&&) = delete;
    void load_altas(const std::string& path_temp, int num);
    void load_atlas(SpriteSheet& sprite_sheet);
    void load_texture(const std::string& image_name, const std::string& path_temp);
    void load_surface(const std::string& image_name, const std::string& path_temp);
    void load_texture_info(const std::string& path, FrameInfo& frame_info);
    void load_surface_info(const std::string& path, FrameInfo& frame_info);
    // 从精灵图到序列帧图集
    void load_sprite_sheet(const std::string& path, SpriteSheet& sprite_sheet);
    void load_music(const std::string& music_name, const std::string& path);

private:
    static std::mutex m_mutex;
    static SDL_Renderer* m_renderer;
    std::unordered_map<std::string, std::shared_ptr<ResourceAtlas>> m_resource_atlas_map;
    //texture和surface的映射用于存放纹理和表面信息
    //texture_info 和 surface_info 的映射用于存放实际帧信息
    std::unordered_map<std::string, SDL_Texture*> m_texture_map;
    std::unordered_map<std::string, SDL_Surface*> m_surface_map;
    std::unordered_map<std::string, TextureInfo> m_texture_info_map;
    std::unordered_map<std::string, SurfaceInfo> m_surface_info_map;
    static UtilVector<int> m_window_size;
    //TODO: 重写下图集类
    std::unordered_map<std::string, Mix_Music*> m_music_map;

};