#include <util/util_parse_sprite_sheet.h>
#include <util/util_log.h>
UtilParseSpriteSheet::UtilParseSpriteSheet(const std::string& file_path) : file_path(file_path) {}

SpriteSheet UtilParseSpriteSheet::parse_data()
{
    std::ifstream fin(file_path);
    if (!fin.is_open())
    {
        UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "Failed to open file " + file_path + "\n"));
        return SpriteSheet();
    }

    nlohmann::json json_data;
    fin >> json_data;

    SpriteSheet sprite_sheet;

    // 解析 frames
    for (const auto& frame : json_data["frames"])
    {
        FrameInfo frame_info;
        frame_info.filename = frame["filename"];
        frame_info.frame.pos.x = frame["frame"]["x"];
        frame_info.frame.pos.y = frame["frame"]["y"];
        frame_info.frame.size.x = frame["frame"]["w"];
        frame_info.frame.size.y = frame["frame"]["h"];
        frame_info.rotated = frame["rotated"];
        frame_info.trimmed = frame["trimmed"];
        frame_info.spriteSourceSize.pos.x = frame["spriteSourceSize"]["x"];
        frame_info.spriteSourceSize.pos.y = frame["spriteSourceSize"]["y"];
        frame_info.spriteSourceSize.size.x = frame["spriteSourceSize"]["w"];
        frame_info.spriteSourceSize.size.y = frame["spriteSourceSize"]["h"];
        frame_info.sourceSize.x = frame["sourceSize"]["w"];
        frame_info.sourceSize.y = frame["sourceSize"]["h"];
        sprite_sheet.frames.push_back(frame_info);
    }

    // 解析 meta
    sprite_sheet.meta.app = json_data["meta"]["app"];
    sprite_sheet.meta.version = json_data["meta"]["version"];
    sprite_sheet.meta.image = json_data["meta"]["image"];
    sprite_sheet.meta.format = json_data["meta"]["format"];
    sprite_sheet.meta.size.size.x = json_data["meta"]["size"]["w"];
    sprite_sheet.meta.size.size.y = json_data["meta"]["size"]["h"];
    sprite_sheet.meta.scale = json_data["meta"]["scale"];

    return sprite_sheet;
}