#ifndef PGE_CORE_SCREENMANAGER_HPP
#define PGE_CORE_SCREENMANAGER_HPP

#include <PicoGameEngine/Core/Config.hpp>

namespace pge
{
    class Screen;

    class PGE_API ScreenManager
    {
    public:
        ScreenManager() = default;

        ScreenManager(const ScreenManager&) = delete;

        ScreenManager(ScreenManager&&) = delete;

        ScreenManager& operator=(const ScreenManager&) = delete;

        ScreenManager& operator=(ScreenManager&&) = delete;

        virtual ~ScreenManager() = default;

    private:
        std::unique_ptr<Screen> current_screen_;
    };
}

#endif
