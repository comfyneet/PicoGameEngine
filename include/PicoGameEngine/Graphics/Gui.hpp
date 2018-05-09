#ifndef PGE_GRAPHICS_GUI_HPP
#define PGE_GRAPHICS_GUI_HPP

#include <memory>
#include <PicoGameEngine/Core/Config.hpp>
#include <PicoGameEngine/Graphics/UiContainer.hpp>
#include <PicoGameEngine/Utils/Vector2.hpp>

namespace pge
{
    class UiElement;

    class PGE_API Gui
    {
    public:
        Gui() = delete;

        explicit Gui(const Vector2U& size);

        Gui(const Gui&) = delete;

        Gui(Gui&&) = delete;

        Gui& operator=(const Gui&) = delete;

        Gui& operator=(Gui&&) = delete;

        virtual ~Gui() = default;

        void add_element(std::unique_ptr<UiElement> element);

        void draw();

    private:
        UiContainer container_;
    };
}

#endif
