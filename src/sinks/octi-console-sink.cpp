/**
 * @file octi-console-sink.cpp
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "octi-logger/sinks/octi-console-sink.h"
#include <iostream>

namespace Octi
{
    namespace Logger
    {
        void ConsoleSink::configure_log_color(const LogLevel & log_level)
        {
            switch (log_level)
            {
                case LogLevel::LL_DEBUG:
                    std::cout << "\e[32m";
                    break;
                case LogLevel::LL_INFO:
                    std::cout << "\e[36m";
                    break;
                case LogLevel::LL_NOTICE:
                    std::cout << "\e[34m";
                    break;
                case LogLevel::LL_WARNING:
                    std::cout << "\e[33m";
                    break;
                case LogLevel::LL_ERROR:
                    std::cout << "\e[31m";
                    break;
            }
        }

        void ConsoleSink::reset_log_color()
        {
            std::cout << "\e[39m";
        }

        ConsoleSink::ConsoleSink(const SinkConfig & config)
            :Sink(config)
        {
            disable_console_color_ = static_cast<bool>(config.get_option_default(SinkOption::SO_CONSOLE_DISABLE_COLOR,0));
        }

        ConsoleSink::~ConsoleSink()
        {

        }

        void ConsoleSink::write(const Log & log, const ChannelPtr & channel)
        {
            // Check if the stream is not null
            if(log.get_stream())
            {
                // Create a temp buffer for date time formatting
                char dtf[1024];

                // Set output buffer
                if(!disable_console_color_)
                {
                    configure_log_color(log.get_log_level());
                }
                
                // Format the log time
                std::time_t time = std::chrono::system_clock::to_time_t(log.get_time_created());
                std::strftime(dtf, sizeof(dtf), "[%d/%m/%Y %H:%M:%S]",std::localtime(&time));;

                // Output to console
                std::cout << dtf << "[" << channel->get_channel_name() << "][" << Log::level_to_string(log.get_log_level()) 
                            << "]: "
                            << log.get_stream()->str();

                // Reset output color
                if(!disable_console_color_)
                {
                    reset_log_color();
                }

                std::cout << std::endl;
            }
        }
    }
}