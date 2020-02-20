/**
 * @file octi-console-sink.h
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef OCTI_CONSOLE_SINK_H_
#define OCTI_CONSOLE_SINK_H_

#include "octi-logger/octi-sink.h"

namespace Octi
{
    namespace Logger
    {
        class ConsoleSink : public Sink
        {
            private:
                bool disable_console_color_;

            private:
                void configure_log_color(const LogLevel &log_level);
                void reset_log_color();

            public:
                ConsoleSink(const SinkConfig &config);
                virtual ~ConsoleSink();
                virtual void write(const Log &log, const ChannelPtr &channel) override;
        };
    }
}

#endif