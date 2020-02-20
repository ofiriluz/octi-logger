/**
 * @file octi-sink-config.h
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef OCTI_SINK_CONFIG_H_
#define OCTI_SINK_CONFIG_H_

#include <string>
#include <vector>
#include <map>
#include <thread>
#include <sstream>

namespace Octi
{
    namespace Logger
    {
        enum SinkOption
        {
            WO_CONSOLE_DISABLE_COLOR,

            WO_FILE_LOG_FILES_PATH,
            WO_FILE_SIZE_PER_LOG_FILE,
            WO_FILE_MAX_LOG_FILES,
            WO_FILE_LOG_FOLDER_PREFIX,
            WO_FILE_SEPERATE_CHANNEL_FILES,

            WO_SYSLOG_NAME
        };
        enum SinkType
        {
            LW_FILE_WRITER,
            LW_CONSOLE_WRITER,
            LW_SYSLOG_WRITER
        };

        class SinkConfig
        {
        private:
            std::map<SinkOption, std::string> options_;
            SinkType sink_type_;
            std::string sink_name_;

        public:
            SinkConfig(const std::string &sink_name, const SinkType &sink_type);
            virtual ~SinkConfig();
            void set_option(const SinkOption &option, const std::string &value);
            void set_option(const SinkOption &option, int value);
            bool remove_option(const SinkOption &option);
            bool has_option(const SinkOption &option) const;
            bool get_option(const SinkOption &option, std::string &value) const;
            bool get_option(const SinkOption &option, int &value) const;
            std::string get_option_default(const SinkOption &option, const std::string &default_value) const;
            int get_option_default(const SinkOption &option, int default_value) const;
            std::string get_sink_name() const;
            SinkType get_sink_type() const;
        };
    }
}

#endif