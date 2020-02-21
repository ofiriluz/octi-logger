/**
 * @file octi-logger.cpp
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "octi-logger/octi-logger.h"
#include "octi-logger/octi-manager.h"

namespace Octi
{
    namespace Logger
    {
        void Logger::write_log(const Log &log) const
        {
            Manager::get_instance().write(log, logger_channel_);
        }

        Logger::Logger(const std::string &channel)
        {
            logger_channel_ = Manager::get_instance().get_channel(channel);
        }

        Logger::~Logger()
        {
        }

        const ChannelPtr &Logger::get_logger_channel() const
        {
            return logger_channel_;
        }

        Log Logger::debug()
        {
            return Log(LogLevel::LL_DEBUG, *this);
        }

        Log Logger::info()
        {
            return Log(LogLevel::LL_INFO, *this);
        }

        Log Logger::notice()
        {
            return Log(LogLevel::LL_NOTICE, *this);
        }

        Log Logger::warning()
        {
            return Log(LogLevel::LL_WARNING, *this);
        }

        Log Logger::error()
        {
            return Log(LogLevel::LL_ERROR, *this);
        }
    }
}