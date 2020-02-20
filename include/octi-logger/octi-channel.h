/**
 * @file octi-channel.h
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef OCTI_CHANNEL_H_
#define OCTI_CHANNEL_H_

#include "octi-log.h"
#include <memory>

namespace Octi
{
    namespace Logger
    {
        class Channel
        {
            private:
                std::string channel_name_;
                LogLevel channel_level_;

            public:
                Channel(const std::string &channel_name, const LogLevel &channel_level);
                virtual ~Channel();
                LogLevel get_log_level() const;
                void set_log_level(const LogLevel &channel_level);
                std::string get_channel_name() const;

                friend class Canager;
        };
        typedef std::shared_ptr<Channel> ChannelPtr;
    }
}

#endif