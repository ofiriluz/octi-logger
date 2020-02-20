/**
 * @file octi-file-sink.h
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef OCTI_FILE_SINK_H_
#define OCTI_FILE_SINK_H_

#include "octi-logger/octi-sink.h"
#include <fstream>

namespace Octi
{
    namespace Logger
    {
        class FileSink : public Sink
        {
            private:
                class File
                {
                public:
                    std::ofstream stream;
                    uint32_t index;

                    File();
                    virtual ~File();
                };

            private:
                std::string folder_name_prefix_;
                std::string log_path_;
                long size_per_file_;
                uint32_t max_files_;
                std::map<std::string, std::shared_ptr<File>> current_files_;
                bool seperate_channel_to_files_;

            private:
                int recursive_folder_creation(const char *dir, mode_t mode);
                void create_log_path();
                void create_log_directory();
                void switch_stream(const std::string &channel);

            public:
                FileSink(const SinkConfig &config);
                virtual ~FileSink();
                virtual void write(const Log & log, const ChannelPtr & channel) override;
        };
    }
}

#endif