#ifndef PGE_CORE_GAME_HPP
#define PGE_CORE_GAME_HPP

#include <memory>
#include <PicoGameEngine/Core/Config.hpp>

namespace pge
{
    class Gui;

    class PGE_API Game
    {
    public:
        Game(const Game&) = delete;

        Game(Game&&) = delete;

        Game& operator=(const Game&) = delete;

        Game& operator=(Game&&) = delete;

        virtual ~Game() = default;

        virtual void init() = 0;

        virtual void draw() = 0;

    protected:
        Game() = default;

        std::unique_ptr<Gui> gui_;
    };
}

#endif
