#include <cctype>
#include <exception>

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
	auto it = m_texture_info_map.find(image_name);
	if (it == m_texture_info_map.end())
	{
		UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "image not found"));
		throw std::runtime_error("Image not found: " + image_name);
	}
	return it->second;
}

SurfaceInfo& ManageResource::get_surface_info(const std::string& image_name)
{
	auto it = m_surface_info_map.find(image_name);
	if (it == m_surface_info_map.end())
	{
		UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "image not found"));
		throw std::runtime_error("Image not found: " + image_name);
	}
	return it->second;
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

void ManageResource::set_window_size(const UtilVector<int>& size)
{
	m_window_size = size;
}

TextureInfo& ManageResource::randon_get_texture()
{
	static auto it = m_texture_info_map.begin();
	if (it != m_texture_info_map.end())
	{
		TextureInfo& info = it->second;
		it++;
		return info;
	}
	else
	{
		it = m_texture_info_map.begin();
		TextureInfo& info = it->second;
		it++;
		return info;
	}
}

UtilVector<int> ManageResource::get_window_size()
{
	return m_window_size;
}

ManageResource::ManageResource() {}

ManageResource::~ManageResource()
{
	//释放图片资源和音频资源
	for (auto& item : m_texture_map)
	{
		if (item.second == nullptr)
		{
			continue;
		}
		SDL_DestroyTexture(item.second);
	}
	for (auto& item : m_surface_map)
	{
		if (item.second == nullptr)
		{
			continue;
		}
		SDL_FreeSurface(item.second);
	}
}

void ManageResource::load_resource()
{
	//加载图片资源和音频资源
	load_surface("window_icon", RESOURCE_DIR"/assets/images/window_icon.png");
	auto_load_directory_resource(RESOURCE_DIR"/assets/atlasses", FileFormat::PNG, FileLoadMode::TEXTURE);
	auto_load_directory_resource(RESOURCE_DIR"/assets/audio", FileFormat::OGG,FileLoadMode::UNSPECIFIED);
	auto_load_directory_resource(RESOURCE_DIR"/assets/images", FileFormat::PNG, FileLoadMode::TEXTURE);
	auto_load_directory_resource(RESOURCE_DIR"/assets/atlasses", FileFormat::JSON, FileLoadMode::SPRITE_SHEET);

	for (auto it = m_sprite_sheet_map.begin(); it != m_sprite_sheet_map.end(); it++)
	{
		SpriteSheet& info = it->second;
		load_atlas(info);
	}
}

void ManageResource::load_altas(const std::string& path_temp, int num)
{

}

void ManageResource::load_atlas(SpriteSheet& info)
{
	for (auto it = info.frames.begin(); it != info.frames.end(); it++)
	{
		std::string& filename = it->filename;

		std::string& frame_name = filename.substr(0, filename.length() - 4);
		int frame_index= atoi(filename.substr(filename.length() - 4,4).c_str());

		auto temp = m_resource_atlas_map.find(frame_name);

		TextureInfo& info = get_texture_info(filename);
		AtlasFrame atlas_frame = { info,frame_index };

		if ( temp!= m_resource_atlas_map.end())
		{
			
			temp->second.add_frame_info(atlas_frame);
		}
		else
		{
			ResourceAtlas new_atlas;
			new_atlas.add_frame_info(atlas_frame);
			m_resource_atlas_map[frame_name] = new_atlas;
		}
	}
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

void ManageResource::load_texture_info(SDL_Texture* texture, FrameInfo& frame_info)
{
	if (texture == nullptr)
	{
		UtilLog::log(LogLevel::DEVELOPPER, LOG_STR("ERROR", "Invalid texture!"));
		return;
	}
	//NOTICE: 目标区域得在具体场景具体设置
	TextureInfo texture_info = { texture, frame_info.frame, frame_info.spriteSourceSize };
	m_texture_info_map[frame_info.filename] = texture_info;
}

void ManageResource::load_sprite_sheet(const std::string& json_path)
{
	UtilParseSpriteSheet parse(json_path);
	SpriteSheet result=parse.parse_data();
	fs::path image(result.meta.image);
	if (result.meta.image == std::string())
	{
		return;
	}
	std::string filename = image.stem().string();
	m_sprite_sheet_map[filename] = result;
	SDL_Texture* texture = get_texture(filename);
	if (texture == nullptr)
	{
		return;
	}
	for (auto& it : result.frames)
	{
		load_texture_info(texture, it);
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

void ManageResource::auto_load_directory_resource(const fs::path& path, FileFormat extension, FileLoadMode mode)
{
	if (!fs::exists(path) || !fs::is_directory(path))
	{
		UtilLog::log(LogLevel::USER, LOG_STR("ERROR", std::string("Not found directory "+path.string())));
		return;
	}
	for (const auto& entry : fs::directory_iterator(path))
	{
		switch (extension)
		{
		case FileFormat::OGG:
			if (entry.path().extension().string() != ".ogg")
			{
				continue;
			}
			load_music(entry.path().filename().stem().string(), entry.path().string());
			break;
		case FileFormat::PNG:
			if (entry.path().extension().string() != ".png")
			{
				continue;
			}
			switch (mode)
			{
			case FileLoadMode::TEXTURE:
				load_texture(entry.path().filename().stem().string(), entry.path().string());
				break;
			case FileLoadMode::SURFACE:
				load_surface(entry.path().filename().stem().string(), entry.path().string());
				break;
			default:
				break;
			}
			break;
		case FileFormat::JSON:
			if (entry.path().extension().string() != ".json")
			{
				continue;
			}
			switch (mode)
			{
			case FileLoadMode::SPRITE_SHEET:
				load_sprite_sheet(entry.path().string());
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

std::mutex ManageResource::m_mutex;

SDL_Renderer* ManageResource::m_renderer = nullptr;

UtilVector<int> ManageResource::m_window_size = UtilVector<int>(1080, 720);