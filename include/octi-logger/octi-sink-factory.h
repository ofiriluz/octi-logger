/**
 * @file octi-sink-factory.h
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef OCTI_SINK_FACTORY_H_
#define OCTI_SINK_FACTORY_H_

#include "octi-logger/octi-sink.h"

namespace Octi
{
    namespace Logger
    {
        class SinkFactory
        {
            private:
                SinkFactory(const SinkFactory &other) = delete;
                SinkFactory operator=(const SinkFactory &other) = delete;
                SinkFactory();

            public:
                static SinkFactory &get_instance();
                virtual ~SinkFactory();
                SinkPtr create_sink(const SinkConfig &sink_config);
        };
    }
}

#endif