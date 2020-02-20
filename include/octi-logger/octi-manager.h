/**
 * @file octi-manager.h
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef OCTI_MANAGER_H_
#define OCTI_MANAGER_H_

#include "octi-channel.h"
#include "octi-manager-config.h"
#include "octi-sink.h"
#include <mutex>

namespace Octi
{
    namespace Logger
    {
        class Manager
        {
            private:
                std::map<std::string, ChannelPtr> channels_;
                std::vector<SinkPtr> sinks_;
                std::mutex sinks_mutex_;
                ManagerConfigPtr config_;
                LogLevel default_log_level_;

            private:
                Manager(const Manager &other) = delete;
                Manager &operator=(const Manager &other) = delete;
                Manager();

            public:
                static Manager &get_instance();
                virtual ~Manager();
                ChannelPtr get_channel(const std::string &name);
                void configure(const ManagerConfigPtr &config);
                void write(const Log &log, const ChannelPtr &channel);
                void clear_sinks();
                void clear_channels();
        };
    }
}

#endif