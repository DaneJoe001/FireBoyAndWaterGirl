#include <resource/resource_atlas.h>
#include <resource/resource_definition.h>

ResourceAtlas::ResourceAtlas(){}

ResourceAtlas::~ResourceAtlas(){}

int ResourceAtlas::get_frame_quantity()
{
	return m_atlas.size();
}

void ResourceAtlas::add_frame_info(AtlasFrame& info)
{
	m_atlas.push_back(info);
}

AtlasFrame ResourceAtlas::get_frame(int index)
{
	for (auto& it : m_atlas)
	{
		if (it.index == index)
		{
			return it;
		}
	}
	return { TextureInfo(),-1};
}