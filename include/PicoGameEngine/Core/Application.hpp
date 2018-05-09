#ifndef PGE_CORE_APPLICATION_HPP
#define PGE_CORE_APPLICATION_HPP

#include <PicoGameEngine/Core/Config.hpp>

namespace pge
{
    class Game;

    class PGE_API Application
    {
    public:
        Application() = delete;

        explicit Application(Game& game);

        Application(const Application&) = delete;

        Application(Application&&) = delete;

        Application& operator=(const Application&) = delete;

        Application& operator=(Application&&) = delete;

        virtual ~Application();

        void start();

        void stop();

    private:
        bool running_;

        Game& game_;
    };
}

#endif
