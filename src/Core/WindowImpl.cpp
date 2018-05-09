#include <Core/WindowImpl.hpp>
#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace priv
{
    GLFWwindow* create(const pge::Vector2U& size, const std::string& title);

    void delete_window(GLFWwindow* glfw_window);
}

namespace pge
{
    WindowImpl::WindowImpl(const Vector2U& size, const std::string& title)
    {
        glfw_window_ = std::unique_ptr<GLFWwindow, std::function<void(GLFWwindow*)>>(
            priv::create(size, title),
            std::bind(&priv::delete_window, std::placeholders::_1));
    }
}

namespace priv
{
    GLFWwindow* create(const pge::Vector2U& size, const std::string& title)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        const auto glfw_window = glfwCreateWindow(size.width, size.height, title.c_str(), nullptr, nullptr);
        if (glfw_window == nullptr) throw std::runtime_error("[GLFW] glfwCreateWindow");

        return glfw_window;
    }

    void delete_window(GLFWwindow* glfw_window)
    {
        glfwDestroyWindow(glfw_window);
    }
}
