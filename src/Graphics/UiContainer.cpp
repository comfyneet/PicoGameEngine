#include <PicoGameEngine/Graphics/UiContainer.hpp>
#include <utility>
#include <PicoGameEngine/Graphics/UiElement.hpp>

namespace pge
{
    void UiContainer::add_element(const std::unique_ptr<UiElement> element)
    {
        elements_.push_back(element);
    }

    void UiContainer::draw()
    {
        for (auto& element : elements_)
        {
            if (element->get_visible())
                element->draw();
        }
    }
}
