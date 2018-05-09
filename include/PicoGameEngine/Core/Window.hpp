#ifndef PGE_CORE_WINDOW_HPP
#define PGE_CORE_WINDOW_HPP

#include <memory>
#include <string>
#include <PicoGameEngine/Core/Config.hpp>
#include <PicoGameEngine/Utils/Vector2.hpp>

namespace pge
{
    class WindowImpl;

    class PGE_API Window
    {
    public:
        Window() = delete;

        Window(const Vector2U& size, const std::string& title);

        Window(const Window&) = delete;

        Window(Window&&) = delete;

        Window& operator=(const Window&) = delete;

        Window& operator=(Window&&) = delete;

        virtual ~Window() = default;

    private:
        std::unique_ptr<WindowImpl> window_impl_;
    };
}

#endif
