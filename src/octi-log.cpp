/**
 * @file octi-log.cpp
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "octi-logger/octi-log.h"
#include "octi-logger/octi-logger.h"

namespace Octi
{
    namespace Logger
    {
        Log::Log(const LogLevel &log_level, const Logger &logger)
        : stream_(nullptr), log_level_(log_level), logger_(logger)
        {
            if (log_level_ >= logger.get_logger_channel()->get_log_level())
            {
                stream_ = new std::ostringstream();
            }
        }

        Log::~Log()
        {
            if (stream_)
            {
                time_created_ = std::chrono::system_clock::now();
                logger_.write_log(*this);
                delete stream_;
            }
        }

        std::string Log::level_to_string(const LogLevel &level)
        {
            switch (level)
            {
                case LogLevel::LL_DEBUG:
                    return "Debug";
                case LogLevel::LL_INFO:
                    return "Info";
                case LogLevel::LL_NOTICE:
                    return "Notice";
                case LogLevel::LL_WARNING:
                    return "Warning";
                default:
                    return "Error";
            }
        }

        LogLevel Log::string_to_level(const std::string &level_str)
        {
            if (level_str == "Info")
            {
                return LogLevel::LL_INFO;
            }
            if (level_str == "Debug")
            {
                return LogLevel::LL_DEBUG;
            }
            if (level_str == "Notice")
            {
                return LogLevel::LL_NOTICE;
            }
            if (level_str == "Warning")
            {
                return LogLevel::LL_WARNING;
            }
            else if (level_str == "Error")
            {
                return LogLevel::LL_ERROR;
            }
            throw std::runtime_error("Invalid Log Level String");
        }

        const std::chrono::time_point<std::chrono::system_clock> &Log::get_time_created() const
        {
            return time_created_;
        }

        const std::ostringstream *Log::get_stream() const
        {
            return stream_;
        }

        const LogLevel &Log::get_log_level() const
        {
            return log_level_;
        }
    }
}