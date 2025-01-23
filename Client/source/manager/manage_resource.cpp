#include <util/util_log.h>
#include <manager/manage_resource.h>

ManageResource& ManageResource::get_instance()
{
	std::lock_guard<std::mutex> lock(m_mutex);
	static ManageResource m_instance;
	return m_instance;
}

void ManageResource::init(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

SDL_Surface* ManageResource::get_surface(const std::string& image_name)
{
	if (m_surface_map.find(image_name) == m_surface_map.end())
	{
		UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "image not found"));
		return nullptr;
	}
	return m_surface_map.at(image_name);
}

SDL_Texture* ManageResource::get_texture(const std::string& image_name)
{
	if (m_texture_map.find(image_name) == m_texture_map.end())
	{
		UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "image not found"));
		return nullptr;
	}
	return m_texture_map.at(image_name);
}

TextureInfo& ManageResource::get_texture_info(const std::string& image_name)
{
	if (m_texture_info_map.find(image_name) == m_texture_info_map.end())
	{
		UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "image not found"));
		//处理一下空引用返回
		//return TextureInfo();
	}
	return m_texture_info_map.at(image_name);
}

SurfaceInfo& ManageResource::get_surface_info(const std::string& image_name)
{
	if (m_surface_info_map.find(image_name) == m_surface_info_map.end())
	{
		UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "image not found"));
		//处理一下空引用返回
		//return SurfaceInfo();
	}
	return m_surface_info_map.at(image_name);
}

Mix_Music* ManageResource::get_music(const std::string& music_name)
{
	if (m_music_map.find(music_name) == m_music_map.end())
	{
		UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "music not found"));
		return nullptr;
	}
	return m_music_map.at(music_name);
}

void ManageResource::set_window_size(const UtilVector& size)
{
	m_window_size = size;
}

UtilVector ManageResource::get_window_size()
{
	return m_window_size;
}

ManageResource::ManageResource() {}

ManageResource::~ManageResource()
{
	//释放图片资源和音频资源
	for (auto& item : m_texture_map)
	{
		SDL_DestroyTexture(item.second);
	}
	for (auto& item : m_surface_map)
	{
		SDL_FreeSurface(item.second);
	}
	for (auto& item : m_texture_info_map)
	{
		SDL_DestroyTexture(item.second.texture);
	}
	for (auto& item : m_surface_info_map)
	{
		SDL_FreeSurface(item.second.surface);
	}
}

void ManageResource::load_resource()
{
	//加载图片资源和音频资源
	load_surface("window_icon", RESOURCE_DIR"/assets/images/window_icon.png");
	load_texture("background_1", RESOURCE_DIR"/assets/images/background_1.png");
	load_texture("background_2", RESOURCE_DIR"/assets/images/background_2.png");
	load_texture("background_3", RESOURCE_DIR"/assets/images/background_3.png");
	load_texture("background_4", RESOURCE_DIR"/assets/images/background_4.png");
	load_texture("background_5", RESOURCE_DIR"/assets/images/background_5.png");
	load_texture("background_6", RESOURCE_DIR"/assets/images/background_6.png");
	load_texture("background_7", RESOURCE_DIR"/assets/images/background_7.png");
	load_texture("background_8", RESOURCE_DIR"/assets/images/background_8.png");

	load_texture("title_crystal", RESOURCE_DIR"/assets/images/title_crystal.png");
	load_texture("title_elements", RESOURCE_DIR"/assets/images/title_elements.png");
	load_texture("title_forest", RESOURCE_DIR"/assets/images/title_forest.png");
	load_texture("title_ice", RESOURCE_DIR"/assets/images/titleIce.png");
	load_texture("title_light", RESOURCE_DIR"/assets/images/title_light.png");

	load_texture("beam_cone_shaped", RESOURCE_DIR"/assets/images/beam_cone_shaped.png");

	load_texture("button_normal", RESOURCE_DIR"/assets/images/button_normal.png");
	load_texture("button_pressed", RESOURCE_DIR"/assets/images/button_pressed.png");

	load_music("background", RESOURCE_DIR"/assets/audio/background.ogg");

}

void ManageResource::load_altas(const std::string& path_temp, int num)
{

}

void ManageResource::load_atlas(SpriteSheet& sprite_sheet)
{

}

void ManageResource::load_texture(const std::string& image_name, const std::string& path_temp)
{
	if (m_texture_map.find(image_name) != m_texture_map.end())
	{
		return;
	}
	SDL_Texture* texture = IMG_LoadTexture(m_renderer, path_temp.c_str());
	if (texture == nullptr)
	{
		UtilLog::log(LogLevel::DEVELOPPER, LOG_STR("ERROR", IMG_GetError()));
		return;
	}
	m_texture_map[image_name] = texture;
}

void ManageResource::load_surface(const std::string& image_name, const std::string& path_temp)
{
	SDL_Surface* surface = IMG_Load(path_temp.c_str());
	if (surface == nullptr)
	{
		UtilLog::log(LogLevel::DEVELOPPER, LOG_STR("ERROR", IMG_GetError()));
		return;
	}
	m_surface_map[image_name] = surface;
}

void ManageResource::load_surface_info(const std::string& path, FrameInfo& frame_info)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == nullptr)
	{
		UtilLog::log(LogLevel::USER, LOG_STR("ERROR", IMG_GetError()));
		return;
	}
	SurfaceInfo surface_info = { surface,frame_info.frame,frame_info.spriteSourceSize };
	m_surface_info_map[frame_info.filename] = surface_info;
}

void ManageResource::load_texture_info(const std::string& path, FrameInfo& frame_info)
{
	SDL_Texture* texture = IMG_LoadTexture(m_renderer, path.c_str());
	if (texture == nullptr)
	{
		UtilLog::log(LogLevel::USER, LOG_STR("ERROR", IMG_GetError()));
		return;
	}
	//NOTICE: 目标区域得在具体场景具体设置
	TextureInfo texture_info = { texture, frame_info.frame, frame_info.spriteSourceSize };
	m_texture_info_map[frame_info.filename] = texture_info;
}

void ManageResource::load_sprite_sheet(const std::string& path, SpriteSheet& sprite_sheet)
{
	std::string full_path = path + sprite_sheet.meta.image;
	for (auto& frame_info : sprite_sheet.frames)
	{
		load_texture_info(frame_info.filename, frame_info);
	}

}

void ManageResource::load_music(const std::string& music_name, const std::string& path)
{
	Mix_Music* music = Mix_LoadMUS(path.c_str());
	if (music == nullptr)
	{
		UtilLog::log(LogLevel::USER, LOG_STR("ERROR", Mix_GetError()));
		return;
	}
	m_music_map[music_name] = music;
}

std::mutex ManageResource::m_mutex;

SDL_Renderer* ManageResource::m_renderer = nullptr;

UtilVector ManageResource::m_window_size = UtilVector(1080, 720);