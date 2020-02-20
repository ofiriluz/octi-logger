/**
 * @file octi-log.h
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef OCTI_LOG_H_
#define OCTI_LOG_H_

#include <sstream>
#include <chrono>

namespace Octi
{
    namespace Logger
    {
        class Logger;
        enum LogLevel
        {
            LL_DEBUG,
            LL_INFO,
            LL_WARN,
            LL_ERROR
        };

        class Log
        {
            private:
                std::ostringstream *stream_;
                LogLevel log_level_;
                const Logger &logger_;
                std::chrono::time_point<std::chrono::system_clock> time_created_;

            public:
                Log(const LogLevel & level, const Logger & logger);
                virtual ~Log();
                static std::string level_to_string(const LogLevel & level);
                static LogLevel string_to_level(const std::string & level_str);
                const std::chrono::time_point<std::chrono::system_clock> &get_time_created() const;
                const std::ostringstream *get_stream() const;
                const LogLevel &get_log_level() const;
                template <class T>
                Log &operator<<(const T &value)
                {
                    if (stream_)
                    {
                        *stream_ << value;
                    }
                    return *this;
                }

                friend class Logger;
        
        };
    }
}

#endif