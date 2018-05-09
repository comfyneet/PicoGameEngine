#ifndef PGE_GRAPHICS_TEXT_HPP
#define PGE_GRAPHICS_TEXT_HPP

#include <cstdint>
#include <string>
#include <utility>
#include <PicoGameEngine/Core/Config.hpp>
#include <PicoGameEngine/Graphics/UiElement.hpp>

namespace pge
{
    class PGE_API Text : public virtual UiElement
    {
    public:
        Text() = delete;

        Text(std::string text, const uint32_t font_size) :
            text_{std::move(text)},
            font_size_{font_size}
        {
        }

        Text(const Text&) = delete;

        Text(Text&&) = delete;

        Text& operator=(const Text&) = delete;

        Text& operator=(Text&&) = delete;

        virtual ~Text() = default;

        void draw() override;

    private:
        std::string text_;

        uint32_t font_size_;
    };
}

#endif
