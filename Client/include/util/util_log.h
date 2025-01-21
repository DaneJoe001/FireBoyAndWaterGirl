#include <iostream>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <mutex>

#include <util/util_danejoe.h>

enum class LogLevel
{
    USER,
    DEVELOPPER
};

class UtilLog
{
public:
    static void set_log_path(LogLevel level, std::string path);
    static void log(LogLevel level, std::string info);
    static void clear_log(LogLevel level);

private:
    UtilLog() = delete;
    ~UtilLog() = delete;
    UtilLog(const UtilLog&) = delete;
    UtilLog& operator=(const UtilLog&) = delete;
private:
    static std::string m_developer_log_path;
    static std::string m_user_log_path;
    static std::mutex m_mutex;
};