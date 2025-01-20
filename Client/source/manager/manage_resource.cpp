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

void ManageResource::load_texture(const std::string image_name, const std::string& path_temp)
{
	if (m_texture_map.find(image_name) != m_texture_map.end())
	{
		return;
	}
	std::cout << "load texture: " << path_temp << std::endl;
	SDL_Texture* texture = IMG_LoadTexture(m_renderer, path_temp.c_str());
	if (texture == nullptr)
	{
        std::cout << "load texture error: " << path_temp << std::endl;
		std::cout << "load texture error: " << IMG_GetError() << std::endl;
		return;
	}
	m_texture_map[image_name] = texture;
}

void ManageResource::load_surface(const std::string image_name, const std::string& path_temp)
{
	m_surface_map[image_name] = IMG_Load(path_temp.c_str());
}

std::mutex ManageResource::m_mutex;

SDL_Renderer* ManageResource::m_renderer = nullptr;