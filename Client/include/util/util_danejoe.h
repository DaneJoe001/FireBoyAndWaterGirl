#pragma once

#include <string>
#include <array>
#include <list>
#include <ostream>

#ifdef _MSC_VER
#define FUNCTION_INFO __FUNCSIG__
#else
#define FUNCTION_INFO __PRETTY_FUNCTION__
#endif

#define DANEJOE_TIME (DaneJoeUtil::get_time_str())

/**
* @brief 用于打印日志的宏
* @param type 日志类型
* @param info 日志信息
* @return 返回一个字符串
**/
#define LOG_STR(type, info) (std::ostringstream() \
    << "[ TIME ]: "<< DANEJOE_TIME \
    << "[ FILE ]: " << __FILE__ << "\n" \
    << "[ LINE ]: " << __LINE__ << "\n" \
    << "[ FUNCTION ]: " << FUNCTION_INFO << "\n" \
    << "[ " << type << " ]: " << info << "\n").str()
/**
* @brief 用于打印日志的宏
* @param stream 用于打印日志的流
* @param type 日志类型
* @param info 日志信息
* @return 返回一个字符串
**/
#define DANEJOE_LOG(stream,type,info)(stream\
    LOG_STR(type, info))

namespace DaneJoeUtil
{
#if defined(__GNUC__)||(__clang__)
    /**
    * @brief 获取类型名称
    * @param data 数据
    * @return 返回类型名称
    **/
    template<class T>
    std::string get_type_name(T data)
    {
        std::string pretty_function = __PRETTY_FUNCTION__;
        int pos_begin = pretty_function.find("T = ");
        if (pos_begin == std::string::npos)
        {
            return std::string();
        }
        pos_begin += 4;
        int pos_end = pretty_function.find(";");
        if (pos_end == std::string::npos)
        {
            pos_end = pretty_function.find("]");
        }
        if (pos_end == std::string::npos)
        {
            return std::string();
        }
        std::string result = pretty_function.substr(pos_begin, pos_end - pos_begin);
        return result;
    }
#endif
    /**
    * @brief 打印数组
    **/
    template<class T>
    void print_array(std::ostream& os, const T& array, const std::string tip = "")
    {
        if (tip == "")
        {
            os << "Values in container: { ";
        }
        else
        {
            os << tip << ": { ";
        }
        std::size_t index = 0;
        std::size_t max_index = array.size() - 1;
        for (const auto& it : array)
        {
            index++;
            os << it;
            if (index <= max_index)
            {
                os << ',';
            }
        }
        os << " }" << std::endl;
    }
    /**
    * @brief 获取当前时间字符串
    **/
    inline std::string get_time_str()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        return std::ctime(&in_time_t);
    }
};