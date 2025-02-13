#include <iostream>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <mutex>

#include <util/util_danejoe.h>

/**
* @class UtilLog
* @brief 日志角色
**/
enum class LogLevel
{
    USER,
    DEVELOPPER
};

/**
* @class UtilLog
* @brief 日志类
**/
class UtilLog
{
public:
    /**
    * @brief 设置日志路径
    * @param level 日志所属角色
    * @param path 日志路径
    **/
    static void set_log_path(LogLevel level, std::string path);
    /**
    * @brief 写入日志
    * @param level 日志所属角色
    * @param info 日志内容
    **/
    static void log(LogLevel level, std::string info);
    /**
    * @brief 清空日志
    * @param level 日志所属角色
    **/
    static void clear_log(LogLevel level);

private:
    UtilLog() = delete;
    ~UtilLog() = delete;
    UtilLog(const UtilLog&) = delete;
    UtilLog& operator=(const UtilLog&) = delete;

private:
    // 开发者日志路径
    static std::string m_developer_log_path;
    // 用户日志路径
    static std::string m_user_log_path;
    // 互斥锁
    static std::mutex m_mutex;
};