/**
 * @file octi-manager-config.h
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef OCTI_MANAGER_CONFIG_H_
#define OCTI_MANAGER_CONFIG_H_

#include <map>
#include <vector>
#include <string>
#include "octi-sink-config.h"

namespace Octi
{
    namespace Logger
    {
        enum LoggerOption
        {
            LG_DEFAULT_CHANNEL_LEVEL
        };

        class ManagerConfig
        {
            private:
                std::vector<SinkConfig> sink_configs_;
                std::map<LoggerOption, std::string> logger_options_;

            private:
                template <class T>
                static T convert_to(const std::string &input)
                {
                    std::stringstream convertor;
                    convertor << input;
                    T out;
                    convertor >> out;
                    return out;
                }
                template <class T>
                static std::string convert_from(const T &input)
                {
                    std::stringstream convertor;
                    convertor << input;
                    return convertor.str();
                }

            public:
                ManagerConfig();
                virtual ~ManagerConfig();
                void set_option(const LoggerOption &option, const std::string &value);
                void set_option(const LoggerOption &option, int value);
                bool has_sink(const std::string &sink_name) const;
                const std::vector<SinkConfig> &get_sinks() const;
                void add_sink(const SinkConfig &config);
                void remove_sink(const std::string &sink_name);
                bool remove_option(const LoggerOption &option);
                bool has_option(const LoggerOption &option) const;
                bool get_option(const LoggerOption &option, std::string &value) const;
                bool get_option(const LoggerOption &option, int &value) const;
                
                friend class SinkConfig;
        };
        typedef std::shared_ptr<ManagerConfig> ManagerConfigPtr;
    }
}

#endif