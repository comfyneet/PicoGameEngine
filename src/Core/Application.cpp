#include <PicoGameEngine/Core/Application.hpp>
#include <mutex>
#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace priv
{
    bool initialized;

    std::mutex mutex;
}

namespace pge
{
    Application::Application(const Game& game) :
        running_{},
        game_{game}
    {
        std::lock_guard<std::mutex> lock(priv::mutex);

        if (priv::initialized) throw std::runtime_error("[PGE] Application::Application");

        if (glfwInit() != GL_TRUE) throw std::runtime_error("[PGE] Application::Application");

        priv::initialized = true;
    }

    Application::~Application()
    {
        glfwTerminate();
        priv::initialized = false;
    }

    void Application::start()
    {
        if (running_) return;

        running_ = true;

        while (running_)
        {
        }
    }

    void Application::stop()
    {
        running_ = false;
    }
}
