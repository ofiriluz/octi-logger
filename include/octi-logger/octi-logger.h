/**
 * @file octi-logger.h
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef OCTI_LOGGER_H_
#define OCTI_LOGGER_H_

#include <string>
#include "octi-channel.h"

namespace Octi
{
    namespace Logger
    {
        class Logger
        {
            private:
                ChannelPtr logger_channel_;

            private:
                void write_log(const Log & log) const;

            public:
                Logger(const std::string & channel);
                virtual ~Logger();

                const ChannelPtr & get_logger_channel() const;

                Log debug();
                Log info();
                Log warn();
                Log error();

                friend class Log;
        };
    }
}

#endif