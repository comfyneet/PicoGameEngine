#ifndef PGE_CORE_GAME_HPP
#define PGE_CORE_GAME_HPP

#include <PicoGameEngine/Core/Config.hpp>

namespace pge
{
    class PGE_API Game
    {
    public:
        Game() = default;

        Game(const Game & ) = delete;

        Game(Game && ) = delete;

        Game & operator=(const Game & ) = delete;

        Game & operator=(Game && ) = delete;

        virtual ~Game() = default;

        virtual void init() = 0;
    
    };
}

#endif
