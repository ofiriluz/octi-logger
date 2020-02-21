CMAKE_MINIMUM_REQUIRED(VERSION 3.7)
PROJECT(octi-logger)

ADD_LIBRARY(octi-logger
    src/octi-channel.cpp
    src/octi-log.cpp
    src/octi-logger.cpp
    src/octi-manager-config.cpp
    src/octi-manager.cpp
    src/octi-sink-config.cpp
    src/octi-sink-factory.cpp
    src/octi-sink.cpp
    src/sinks/octi-console-sink.cpp
    src/sinks/octi-file-sink.cpp
    src/sinks/octi-syslog-sink.cpp
)

ADD_LIBRARY(Octi::octi-logger ALIAS octi-logger)

TARGET_INCLUDE_DIRECTORIES(octi-logger
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${CMAKE_CURRENT_SOURCE_DIR}/../build/deps/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

TARGET_COMPILE_FEATURES(octi-logger PRIVATE cxx_auto_type)
TARGET_COMPILE_OPTIONS(octi-logger PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall>)
SET_PROPERTY(TARGET octi-logger PROPERTY POSITION_INDEPENDENT_CODE ON)
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")

INCLUDE(GNUInstallDirs)

INSTALL(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

INSTALL(TARGETS octi-logger
    EXPORT octi-logger-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)