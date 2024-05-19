#pragma once

namespace al
{
    enum eLogLevel
    {
        VERBOSE = 1 << 0,
        INFO = 1 << 1,
        WARNING = 1 << 2,
        FATAL = 1 << 3
    };
}