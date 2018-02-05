#ifndef PGE_UTILS_UTILS_HPP
#define PGE_UTILS_UTILS_HPP

#include <cstdint>
#include <PicoGameEngine/Core/Config.hpp>

namespace pge
{
    class PGE_API Utils
    {
    public:
        static int32_t random(int32_t min, int32_t max);

        Utils() = delete;
    
    };
}

#endif
