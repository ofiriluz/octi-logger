/**
 * @file octi-channel.cpp
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "octi-logger/octi-channel.h"

namespace Octi
{
    namespace Logger
    {
        Channel::Channel(const std::string &channel_name, const LogLevel &channel_level)
            : channel_name_(channel_name), channel_level_(channel_level)
        {
        }

        Channel::~Channel()
        {
        }

        LogLevel Channel::get_log_level() const
        {
            return channel_level_;
        }

        void Channel::set_log_level(const LogLevel &channel_level)
        {
            channel_level_ = channel_level;
        }

        std::string Channel::get_channel_name() const
        {
            return channel_name_;
        }
    }
}