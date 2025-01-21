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
	return m_surface_map.at(image_name);
}

SDL_Texture* ManageResource::get_texture(const std::string& image_name)
{
	return m_texture_map.at(image_name);
}

TextureInfo& ManageResource::get_texture_info(const std::string& image_name)
{
	return m_texture_info_map.at(image_name);
}

SurfaceInfo& ManageResource::get_surface_info(const std::string& image_name)
{
	return m_surface_info_map.at(image_name);
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
	load_texture("Beam", RESOURCE_DIR"/assets/images/Beam.png");
	load_texture("GameNameCrystal", RESOURCE_DIR"/assets/images/GameNameCrystal.png");
	load_texture("GameNameElements", RESOURCE_DIR"/assets/images/GameNameElements.png");
	load_texture("GameNameForest", RESOURCE_DIR"/assets/images/GameNameForest.png");
	load_texture("GameNameIce", RESOURCE_DIR"/assets/images/GameNameIce.png");
	load_texture("GameNameLight", RESOURCE_DIR"/assets/images/GameNameLight.png");
	load_texture("TempleHall", RESOURCE_DIR"/assets/images/TempleHall.png");
	load_texture("TempleHallCrystal", RESOURCE_DIR"/assets/images/TempleHallCrystal.png");
	load_texture("TempleHallFire", RESOURCE_DIR"/assets/images/TempleHallFire.png");
	load_texture("TempleHallForest", RESOURCE_DIR"/assets/images/TempleHallForest.png");
	load_texture("TempleHallIce", RESOURCE_DIR"/assets/images/TempleHallIce.png");
	load_texture("TempleHallLight", RESOURCE_DIR"/assets/images/TempleHallLight.png");
	load_texture("TempleHallWater", RESOURCE_DIR"/assets/images/TempleHallWater.png");
	load_texture("TempleHallWind", RESOURCE_DIR"/assets/images/TempleHallWind.png");
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

void ManageResource::set_window_size(const UtilVector& size)
{
	m_window_size = size;
}

UtilVector ManageResource::get_window_size()
{
	return m_window_size;
}

std::mutex ManageResource::m_mutex;

SDL_Renderer* ManageResource::m_renderer = nullptr;

UtilVector ManageResource::m_window_size = UtilVector(1080, 720);