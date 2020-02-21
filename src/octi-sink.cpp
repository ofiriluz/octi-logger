/**
 * @file octi-sink.cpp
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "octi-logger/octi-sink.h"

namespace Octi
{
    namespace Logger
    {
        const SinkConfig & Sink::get_config() const
        {
            return config_;
        }

        Sink::Sink(const SinkConfig &config)
            : config_(config)
        {
        }

        Sink::~Sink()
        {
        }
    }
}