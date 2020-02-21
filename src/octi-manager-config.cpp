/**
 * @file octi-manager-config.cpp
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "octi-logger/octi-manager-config.h"

namespace Octi
{
    namespace Logger
    {
        ManagerConfig::ManagerConfig()
        {
        }

        ManagerConfig::~ManagerConfig()
        {
        }

        void ManagerConfig::set_option(const LoggerOption &option, const std::string &value)
        {
            logger_options_[option] = value;
        }

        void ManagerConfig::set_option(const LoggerOption &option, int value)
        {
            set_option(option, convert_from<int>(value));
        }

        bool ManagerConfig::has_sink(const std::string &sink_name) const
        {
            for (auto &&w : sink_configs_)
            {
                if (w.get_sink_name() == sink_name)
                {
                    return true;
                }
            }
            return false;
        }

        const std::vector<SinkConfig> &ManagerConfig::get_sinks() const
        {
            return sink_configs_;
        }

        void ManagerConfig::add_sink(const SinkConfig &sink)
        {
            sink_configs_.push_back(sink);
        }

        bool ManagerConfig::remove_option(const LoggerOption &option)
        {
            if (!has_option(option))
            {
                return false;
            }
            logger_options_.erase(option);
            return true;
        }

        bool ManagerConfig::has_option(const LoggerOption &option) const
        {
            return logger_options_.find(option) != logger_options_.end();
        }

        bool ManagerConfig::get_option(const LoggerOption &option, std::string &value) const
        {
            if (has_option(option))
            {
                value = logger_options_.at(option);
                return true;
            }
            return false;
        }

        bool ManagerConfig::get_option(const LoggerOption &option, int &value) const
        {
            std::string s;
            if (get_option(option, s))
            {
                value = convert_to<int>(s);
                return true;
            }
            return false;
        }

        void ManagerConfig::remove_sink(const std::string &sink_name)
        {
            for (size_t i = 0; i < sink_configs_.size(); i++)
            {
                if (sink_configs_[i].get_sink_name() == sink_name)
                {
                    sink_configs_.erase(sink_configs_.begin() + i);
                    return;
                }
            }
        }
    }
}