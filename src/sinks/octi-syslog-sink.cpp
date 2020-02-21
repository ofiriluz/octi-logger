/**
 * @file octi-syslog-sink.cpp
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "octi-logger/sinks/octi-syslog-sink.h"
#include <syslog.h>

namespace Octi
{
    namespace Logger
    {
        SyslogSink::SyslogSink(const SinkConfig & config)
        :Sink(config)
        {
            syslog_name_ = config.get_option_default(SinkOption::SO_SYSLOG_NAME, "Logger");
        }

        SyslogSink::~SyslogSink()
        {

        }

        void SyslogSink::write(const Log & log, const ChannelPtr & channel)
        {
            // Check if the stream is not null
            if(log.get_stream())
            {
                // Create a temp buffer for date time formatting
                char dtf[1024];
                
                // Format the log time
                std::time_t time = std::chrono::system_clock::to_time_t(log.get_time_created());
                std::strftime(dtf, sizeof(dtf), "[%d/%m/%Y %H:%M:%S]",std::localtime(&time));;

                std::stringstream ss;
                ss << dtf << "[" << channel->get_channel_name() << "][" << Log::level_to_string(log.get_log_level()) 
                            << "]: "
                            << log.get_stream()->str();

                // Write to syslog
                openlog(syslog_name_.c_str(), LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
                syslog(LOG_INFO, ss.str().c_str(), NULL);
                closelog();
            }
        }
    }
}