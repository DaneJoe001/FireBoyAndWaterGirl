#pragma once

#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

#include <SDL.h>
#include <SDL_image.h>

#include <resource/resource_atlas.h>
#include <util/util_vector.h>
#include <util/util_parse_sprite_sheet.h>

class ManageResource
{
public:
    static ManageResource& get_instance();
    //在初始化renderer之后才能初始化资源
    void load_resource();
    static void init(SDL_Renderer* renderer);
    SDL_Texture* get_texture(const std::string& image_name);
    SDL_Surface* get_surface(const std::string& image_name);
private:
    ManageResource();
    ~ManageResource();
    ManageResource(const ManageResource&) = delete;
    ManageResource& operator=(const ManageResource&) = delete;
    ManageResource(ManageResource&&) = delete;
    ManageResource& operator=(ManageResource&&) = delete;
    void load_altas(const std::string& path_temp, int num);
    void load_atlas(SpriteSheet& sprite_sheet);
    void load_texture(const std::string image_name, const std::string& path_temp);
    void load_surface(const std::string image_name, const std::string& path_temp);

private:
    static std::mutex m_mutex;
    static SDL_Renderer* m_renderer;
    std::unordered_map<std::string, std::shared_ptr<ResourceAtlas>> m_resource_atlas_map;
    std::unordered_map<std::string, SDL_Texture*> m_texture_map;
    std::unordered_map<std::string, SDL_Surface*> m_surface_map;

};