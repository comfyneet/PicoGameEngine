#ifndef PGE_CORE_APPLICATION_HPP
#define PGE_CORE_APPLICATION_HPP

#include <PicoGameEngine/Core/Config.hpp>
#include <PicoGameEngine/Graphics/Gui.hpp>

namespace pge
{
    class Game;

    class PGE_API Application
    {
    public:
        Application() = delete;

        explicit Application(const Game & game);

        Application(const Application & ) = delete;

        Application(Application && ) = delete;

        Application & operator=(const Application & ) = delete;

        Application & operator=(Application && ) = delete;

        virtual ~Application();

        Gui & get_gui() {return gui_; }

        void start();

        void stop();

    private:
        bool running_;

        Gui gui_;

        const Game & game_;
    
    };
}

#endif
