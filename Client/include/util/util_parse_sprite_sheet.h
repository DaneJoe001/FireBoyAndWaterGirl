#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include <util/util_vector.h>

struct ImageArea {
    UtilVector pos;
    UtilVector size;
};

struct FrameInfo {
    std::string filename;
    ImageArea frame;
    bool rotated;
    bool trimmed;
    ImageArea spriteSourceSize;
    UtilVector sourceSize;
};

struct Meta {
    std::string app;
    std::string version;
    std::string image;
    std::string format;
    ImageArea size;
    std::string scale;
};

struct SpriteSheet
{
    SpriteSheet() = default;
    std::vector<FrameInfo> frames;
    Meta meta;
};

class UtilParseSpriteSheet
{
public:
    UtilParseSpriteSheet(const std::string& file_path);
    SpriteSheet parse_data();

private:
    std::string file_path;
};
