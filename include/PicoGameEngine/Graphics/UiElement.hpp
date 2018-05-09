#ifndef PGE_GRAPHICS_UIELEMENT_HPP
#define PGE_GRAPHICS_UIELEMENT_HPP

#include <PicoGameEngine/Core/Config.hpp>

namespace pge
{
    class PGE_API UiElement
    {
    public:
        UiElement(const UiElement&) = delete;

        UiElement(UiElement&&) = delete;

        UiElement& operator=(const UiElement&) = delete;

        UiElement& operator=(UiElement&&) = delete;

        virtual ~UiElement() = default;

        virtual void draw() = 0;

        bool get_visible() const { return visible_; }

        void set_visible(const bool visible) { visible_ = visible; }

    protected:
        UiElement() :
            visible_{}
        {
        }

    private:
        bool visible_;
    };
}

#endif
