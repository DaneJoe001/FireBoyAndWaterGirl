#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>


struct ImageArea
{
    int x;
    int y;
    int w;
    int h;
};

struct FrameInfo
{
    std::string filename;
    ImageArea frame;
    bool rotated;
    bool trimmed;
    ImageArea spriteSourceSize;
    ImageArea sourceSize;
};

struct Meta
{
    std::string app;
    std::string version;
    std::string image;
    std::string format;
    ImageArea size;
    std::string scale;
};

struct SpriteSheet
{
    std::vector<FrameInfo> frames;
    Meta meta;
    void show_data() const
    {
        std::cout << "Frames quantity: " << frames.size() << '\n' << std::endl;
        for (const auto& frame : frames)
        {
            std::cout << "filename: " << frame.filename << std::endl;
            std::cout << "frame: " << frame.frame.x << ", " << frame.frame.y << ", " << frame.frame.w << ", " << frame.frame.h << std::endl;
            std::cout << "rotated: " << frame.rotated << std::endl;
            std::cout << "trimmed: " << frame.trimmed << std::endl;
            std::cout << std::endl;
        }
        std::cout << "Meta data:" << std::endl;
        std::cout << "app: " << meta.app << std::endl;
        std::cout << "version: " << meta.version << std::endl;
        std::cout << "image: " << meta.image << std::endl;
        std::cout << "format: " << meta.format << std::endl;
        std::cout << "size: " << meta.size.w << ", " << meta.size.h << std::endl;
        std::cout << "scale: " << meta.scale << std::endl;
    }
};

template<class T>
class UtilParseJson {
public:
    UtilParseJson(std::string file_path) : file_path(file_path) {}
    virtual T parse_data() = 0;
protected:
    std::string file_path;
};

class UtilParseSpriteSheet : public UtilParseJson<SpriteSheet> {
public:
    SpriteSheet parse_data() override
    {
        std::ifstream fin(file_path);
        if (!fin.is_open())
        {
            std::cout << "Error: Failed to open file: " << file_path << std::endl;
            return SpriteSheet();
        }
        SpriteSheet sprite_sheet;
        std::string line;
        while (std::getline(fin, line))
        {
            std::size_t pos = std::string::npos;
            pos = line.find("\"frames\":");
            if (pos != std::string::npos)
            {
                FrameInfo frame_info;
                while (std::getline(fin, line))
                {
                    if (line.find("\"meta\":") != std::string::npos)
                    {
                        break;
                    }
                    if (line.find("\"filename\":") != std::string::npos)
                    {
                        std::sscanf(line.c_str(), "\"filename\":\"%s\"", frame_info.filename);
                    }
                    else if (line.find("\"frame\":") != std::string::npos)
                    {
                        std::sscanf(line.c_str(), "\"frame\":{\"x\":%d,\"y\":%d,\"w\":%d,\"h\":%d}", &frame_info.frame.x, &frame_info.frame.y, &frame_info.frame.w, &frame_info.frame.h);
                    }
                    else if (line.find("\"rotated\":") != std::string::npos)
                    {
                        std::string bool_value;
                        std::sscanf(line.c_str(), "\"rotated\":%s", bool_value);
                        if (bool_value == "true")
                        {
                            frame_info.rotated = true;
                        }
                        else
                        {
                            frame_info.rotated = false;
                        }
                    }
                    else if (line.find("\"trimmed\":") != std::string::npos)
                    {
                        std::string bool_value;
                        std::sscanf(line.c_str(), "\"trimmed\":%s", bool_value);
                        if (bool_value == "true")
                        {
                            frame_info.trimmed = true;
                        }
                        else
                        {
                            frame_info.trimmed = false;
                        }
                    }
                    else if (line.find("\"spriteSourceSize\":") != std::string::npos)
                    {
                        std::sscanf(line.c_str(), "\"spriteSourceSize\":{\"x\":%d,\"y\":%d,\"w\":%d,\"h\":%d}", &frame_info.spriteSourceSize.x, &frame_info.spriteSourceSize.y, &frame_info.spriteSourceSize.w, &frame_info.spriteSourceSize.h);
                    }
                    else if (line.find("\"sourceSize\":") != std::string::npos)
                    {
                        std::sscanf(line.c_str(), "\"sourceSize\":{\"w\":%d,\"h\":%d}", &frame_info.sourceSize.w, &frame_info.sourceSize.h);
                        sprite_sheet.frames.push_back(frame_info);
                    }
                }
                continue;
            }
            pos = line.find("\"app\":");
            if (pos != std::string::npos)
            {
                sprite_sheet.meta.app = line.substr(pos + 8, line.length() - pos - 9);
                continue;
            }
            pos = line.find("\"version\":");
            if (pos != std::string::npos)
            {
                std::sscanf(line.c_str(), "\"version\":\"%s\"", sprite_sheet.meta.version);
                continue;
            }
            pos = line.find("\"image\":");
            if (pos != std::string::npos)
            {
                std::sscanf(line.c_str(), "\"image\":\"%s\"", sprite_sheet.meta.image);
                continue;
            }
            pos = line.find("\"format\":");
            if (pos != std::string::npos)
            {
                std::sscanf(line.c_str(), "\"format\":\"%s\"", sprite_sheet.meta.format);
                continue;
            }
            pos = line.find("\"size\":");
            if (pos != std::string::npos)
            {
                std::sscanf(line.c_str(), "\"size\":{\"w\":%d,\"h\":%d}", &sprite_sheet.meta.size.w, &sprite_sheet.meta.size.h);
                continue;
            }
            pos = line.find("\"scale\":");
            if (pos != std::string::npos)
            {
                std::sscanf(line.c_str(), "\"scale\":\"%s\"", sprite_sheet.meta.scale);
                break;
            }
        }
        std::cout << "Finished to parse data!" << std::endl;
    }
};