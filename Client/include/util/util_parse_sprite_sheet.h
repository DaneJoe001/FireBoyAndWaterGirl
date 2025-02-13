#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include <resource/resource_definition.h>

/**
* @class UtilParseSpriteSheet
* @brief 精灵图解析器
**/
class UtilParseSpriteSheet
{
public:
    /**
    * @brief 构造函数
    * @param file_path 精灵图数据文件路径
    **/
    UtilParseSpriteSheet(const std::string& file_path);
    /**
    * @brief 解析精灵图数据
    * @return 精灵图数据
    **/
    SpriteSheet parse_data();

private:
    // 精灵图数据文件路径
    std::string file_path;
};
