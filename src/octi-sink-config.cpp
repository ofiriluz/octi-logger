/**
 * @file octi-sink-config.cpp
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "octi-logger/octi-sink-config.h"
#include "octi-logger/octi-manager-config.h"

namespace Octi
{
    namespace Logger
    {
        SinkConfig::SinkConfig(const std::string &sink_name, const SinkType &sink_type)
        : sink_type_(sink_type), sink_name_(sink_name)
        {
        }

        SinkConfig::~SinkConfig()
        {
        }

        void SinkConfig::set_option(const SinkOption &option, const std::string &value)
        {
            options_[option] = value;
        }

        void SinkConfig::set_option(const SinkOption &option, int value)
        {
            set_option(option, ManagerConfig::convert_from<int>(value));
        }

        bool SinkConfig::remove_option(const SinkOption &option)
        {
            if (has_option(option))
            {
                options_.erase(option);
                return true;
            }
            return false;
        }

        bool SinkConfig::has_option(const SinkOption &option) const
        {
            return options_.find(option) != options_.end();
        }

        bool SinkConfig::get_option(const SinkOption &option, std::string &value) const
        {
            if (has_option(option))
            {
                value = options_.at(option);
                return true;
            }
            return false;
        }

        bool SinkConfig::get_option(const SinkOption &option, int &value) const
        {
            std::string s;
            if (get_option(option, s))
            {
                try
                {
                    value = ManagerConfig::convert_to<int>(s);
                    return true;
                }
                catch (...)
                {
                    return false;
                }
            }
            return false;
        }

        std::string SinkConfig::get_option_default(const SinkOption &option, const std::string &default_value) const
        {
            if (has_option(option))
            {
                return options_.at(option);
            }
            return default_value;
        }

        int SinkConfig::get_option_default(const SinkOption &option, int default_value) const
        {
            std::string s = get_option_default(option, ManagerConfig::convert_from<int>(default_value));
            try
            {
                int i = ManagerConfig::convert_to<int>(s);
                return i;
            }
            catch (...)
            {
                return default_value;
            }
        }

        std::string SinkConfig::get_sink_name() const
        {
            return sink_name_;
        }

        SinkType SinkConfig::get_sink_type() const
        {
            return sink_type_;
        }
    }
}