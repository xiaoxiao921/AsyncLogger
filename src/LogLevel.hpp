#pragma once

#undef ERROR

namespace al
{
    enum eLogLevel
    {
        DEBUG = 1 << 0,
        INFO = 1 << 1,
        WARNING = 1 << 2,
        ERROR = 1 << 3
    };
}