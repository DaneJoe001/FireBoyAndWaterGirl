#include <resource/resource_atlas.h>
#include <resource/resource_definition.h>

ResourceAtlas::ResourceAtlas(){}

ResourceAtlas::~ResourceAtlas(){}

void ResourceAtlas::add_frame_info(AtlasFrame& info)
{
	m_atlas.push_back(info);
}