/**
 * @file octi-manager.cpp
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "octi-logger/octi-manager.h"
#include "octi-logger/octi-sink-factory.h"

namespace Octi
{
    namespace Logger
    {
        Manager::Manager()
        : config_(new ManagerConfig()), default_log_level_(LogLevel::LL_DEBUG)
        {
        }

        Manager &Manager::get_instance()
        {
            static Manager manager;
            return manager;
        }

        Manager::~Manager()
        {
            clear_sinks();
            clear_channels();
        }

        ChannelPtr Manager::get_channel(const std::string &name)
        {
            if (channels_.find(name) == channels_.end())
            {
                channels_[name] = ChannelPtr(new Channel(name, default_log_level_));
            }
            return channels_[name];
        }

        void Manager::configure(const ManagerConfigPtr &config)
        {
            clear_sinks();
            config_ = config;

            // Change the default level if requested by config
            if (config_->has_option(LoggerOption::LG_DEFAULT_CHANNEL_LEVEL))
            {
                int default_level;
                if (config_->get_option(LoggerOption::LG_DEFAULT_CHANNEL_LEVEL, default_level))
                {
                    default_log_level_ = static_cast<LogLevel>(default_level);
                }
            }

            // Create all the sinks
            for (auto &&sink_config : config_->get_sinks())
            {
                SinkPtr sink = SinkFactory::get_instance().create_sink(sink_config);
                if (sink)
                {
                    sinks_.push_back(sink);
                }
            }
        }

        void Manager::write(const Log &log, const ChannelPtr &channel)
        {
            std::lock_guard<std::mutex> lock(sinks_mutex_);
            for (auto &&sink : sinks_)
            {
                sink->write(log, channel);
            }
        }

        void Manager::clear_sinks()
        {
            sinks_.clear();
        }

        void Manager::clear_channels()
        {
            channels_.clear();
        }
    }
}