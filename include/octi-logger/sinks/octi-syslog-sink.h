/**
 * @file octi-syslog-sink.h
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef OCTI_SYSLOG_SINK_H_
#define OCTI_SYSLOG_SINK_H_

#include "octi-logger/octi-sink.h"

namespace Octi
{
    namespace Logger
    {
        class SyslogSink : public Sink
        {
            private:
                std::string syslog_name_;

            public:
                SyslogSink(const SinkConfig &config);
                virtual ~SyslogSink();
                virtual void write(const Log &log, const ChannelPtr &channel);
        };
    }
}

#endif
