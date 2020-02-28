/**
 * @file octi-sink-factory.cpp
 * @author ofir iluz (iluzofir@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "octi-logger/octi-sink-factory.h"
#include "octi-logger/sinks/octi-console-sink.h"
#include "octi-logger/sinks/octi-file-sink.h"
#include "octi-logger/sinks/octi-syslog-sink.h"

namespace Octi
{
    namespace Logger
    {
        SinkFactory::SinkFactory()
        {
        }

        SinkFactory &SinkFactory::instance()
        {
            static SinkFactory factory;
            return factory;
        }

        SinkFactory::~SinkFactory()
        {
        }

        SinkPtr SinkFactory::create_sink(const SinkConfig &sink_config)
        {
            if (sink_config.get_sink_type() == SinkType::ST_CONSOLE_WRITER)
            {
                return SinkPtr(new ConsoleSink(sink_config));
            }
            else if (sink_config.get_sink_type() == SinkType::ST_FILE_WRITER)
            {
                return SinkPtr(new FileSink(sink_config));
            }
            else if(sink_config.get_sink_type() == SinkType::ST_SYSLOG_WRITER)
            {
                return SinkPtr(new SyslogSink(sink_config));
            }
            return SinkPtr();
        }
    }
}