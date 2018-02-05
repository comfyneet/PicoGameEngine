#include <PicoGameEngine/Core/Window.hpp>
#include <Core/WindowImpl.hpp>

namespace pge
{
    Window::Window(const Vector2U& size, const std::string& title) :
        window_impl_{std::make_unique<WindowImpl>(size, title)}
    {
    }
}
