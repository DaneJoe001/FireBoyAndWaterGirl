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

//构建日志字符串
#define LOG_STR(type, info) \
    (std::ostringstream() << "[ TIME ]: "<< DANEJOE_TIME \
                          << "[ FILE ]: " << __FILE__ << "\n" \
                          << "[ LINE ]: " << __LINE__ << "\n" \
                          << "[ FUNCTION ]: " << FUNCTION_INFO << "\n" \
                          << "[ " << type << " ]: " << info << "\n").str()

//可用于打印日志的宏
//__FILE__用于打印整个文件的路径
//__LINE__用于打印当前行号
//__func__用于打印函数名
//__PRETTY_FUNCTION__用于打印函数名，包括返回值和参数
//__PRETTY_FUNCTION__可以打印模板参数
#define DANEJOE_LOG(stream,type,info)(stream\
    LOG_STR(type, info))

namespace DaneJoeUtil
{
#if defined(__GNUC__)||(__clang__)
    //用于打印任意变量类型的函数(MSVC不适用)
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
    inline std::string get_time_str()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        return std::ctime(&in_time_t);
    }
};