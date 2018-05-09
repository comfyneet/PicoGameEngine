#ifndef PGE_GRAPHICS_BUTTON_HPP
#define PGE_GRAPHICS_BUTTON_HPP

#include <cstdint>
#include <PicoGameEngine/Core/Config.hpp>
#include <PicoGameEngine/Graphics/UiElement.hpp>

namespace pge
{
    class PGE_API Button : public virtual UiElement
    {
    public:
        Button() = default;

        Button(const Button&) = delete;

        Button(Button&&) = delete;

        Button& operator=(const Button&) = delete;

        Button& operator=(Button&&) = delete;

        virtual ~Button() = default;

        void draw() override;
    };
}

#endif
