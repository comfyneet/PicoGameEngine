#include <PicoGameEngine/Utils/Utils.hpp>
#include <random>

namespace priv
{
    std::random_device seeder;

    std::mt19937 engine(seeder());
}

namespace pge
{
    int32_t Utils::random(const int32_t min, const int32_t max)
    {
        const std::uniform_int_distribution<int32_t> dist(min, max);

        return dist(priv::engine);
    }
}
