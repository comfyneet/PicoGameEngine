#ifndef PGE_GRAPHICS_GUI_HPP
#define PGE_GRAPHICS_GUI_HPP

#include <memory>
#include <PicoGameEngine/Core/Config.hpp>
#include <PicoGameEngine/Graphics/UiContainer.hpp>

namespace pge
{
    class UiElement;

    class PGE_API Gui
    {
        friend class Application;

    public:
        Gui(const Gui & ) = delete;

        Gui(Gui && ) = delete;

        Gui & operator=(const Gui & ) = delete;

        Gui & operator=(Gui && ) = delete;

        ~Gui() = default;

        //void add_element(std::unique_ptr<UiElement> element);

    private:
        Gui() = default;

        UiContainer container_;
    
    };
}

#endif
