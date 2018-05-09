#include <PicoGameEngine/Graphics/Gui.hpp>
#include <utility>
#include <PicoGameEngine/Graphics/UiElement.hpp>

namespace pge
{
    Gui::Gui(const Vector2U&)
    {
    }

    void Gui::add_element(std::unique_ptr<UiElement> element)
    {
        container_.add_element(std::move(element));
    }

    void Gui::draw()
    {
        container_.draw();
    }
}
