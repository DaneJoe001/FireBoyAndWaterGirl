#include <util/util_log.h>

void UtilLog::set_log_path(LogLevel level, std::string path)
{
    if (level == LogLevel::DEVELOPPER)
    {
        m_developer_log_path = path;
    }
    else if (level == LogLevel::USER)
    {
        m_user_log_path = path;
    }
}

void UtilLog::log(LogLevel level, std::string info)
{
    if (level == LogLevel::DEVELOPPER)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::fstream fout(m_developer_log_path, std::ios::app);
        if (!fout.is_open())
        {
            std::cout << "[ ERROR ]: Failed to open developer log file." << std::endl;
            return;
        }
        fout << info << std::endl;
        fout.close();
    }
    else if (level == LogLevel::USER)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::fstream fout(m_user_log_path, std::ios::app);
        if (!fout.is_open())
        {
            std::cout << "[ ERROR ]: Failed to open developer log file." << std::endl;
            return;
        }
        fout << info << std::endl;
        fout.close();
    }

}

void UtilLog::clear_log(LogLevel level)
{
    if (level == LogLevel::DEVELOPPER)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::ofstream fout(m_developer_log_path, std::ios::trunc);
        fout.close();
    }
    else if (level == LogLevel::USER)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::ofstream fout(m_user_log_path, std::ios::trunc);
        fout.close();
    }
}

std::string UtilLog::m_developer_log_path = RESOURCE_DIR"/logs/developer.log";
std::string UtilLog::m_user_log_path = RESOURCE_DIR"/logs/user.log";
std::mutex UtilLog::m_mutex;