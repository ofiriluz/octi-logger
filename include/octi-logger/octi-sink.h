/**
 * @file octi-sink.h
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef OCTI_SINK_H_
#define OCTI_SINK_H_

#include "octi-channel.h"
#include "octi-sink-config.h"

namespace Octi
{
    namespace Logger
    {
        class Sink
        {
            private:
                const SinkConfig config_;

            protected:
                const SinkConfig &get_config() const;

            public:
                Sink(const SinkConfig &config);
                virtual ~Sink();
                virtual void write(const Log &log, const ChannelPtr &channel) = 0;
        };
        typedef std::shared_ptr<Sink> SinkPtr;
    }
}

#endif