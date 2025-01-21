#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include <resource/resource_definition.h>


class UtilParseSpriteSheet
{
public:
    UtilParseSpriteSheet(const std::string& file_path);
    SpriteSheet parse_data();

private:
    std::string file_path;
};
