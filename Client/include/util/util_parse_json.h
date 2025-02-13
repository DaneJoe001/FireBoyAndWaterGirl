#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

/**
* @class UtilParseJson
* @brief 解析json文件
**/
template<class T>
class UtilParseJson 
{
public:
    /**
    * @brief 构造函数
    * @param file_path json文件路径
    **/
    UtilParseJson(std::string file_path) : file_path(file_path) {}
    /**
    * @brief 解析json文件
    **/
    virtual T parse_data() = 0;

protected:
    // 文件路径
    std::string file_path;
};