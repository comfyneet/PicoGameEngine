#ifndef PGE_CORE_WINDOWIMPL_HPP
#define PGE_CORE_WINDOWIMPL_HPP

#include <functional>
#include <memory>
#include <string>
#include <PicoGameEngine/Core/Config.hpp>
#include <PicoGameEngine/Utils/Vector2.hpp>

struct GLFWwindow;

namespace pge
{
    class PGE_API WindowImpl
    {
    public:
        WindowImpl() = delete;

        WindowImpl(const Vector2U & size, const std::string & title);

        WindowImpl(const WindowImpl & ) = delete;

        WindowImpl(WindowImpl && ) = delete;

        WindowImpl & operator=(const WindowImpl & ) = delete;

        WindowImpl & operator=(WindowImpl && ) = delete;

        virtual ~WindowImpl() = default;

    private:
        std::unique_ptr<GLFWwindow, std::function<void(GLFWwindow*)>> glfw_window_;
    
    };
}

#endif
