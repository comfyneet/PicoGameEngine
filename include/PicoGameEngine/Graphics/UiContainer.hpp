#ifndef PGE_GRAPHICS_UICONTAINER_HPP
#define PGE_GRAPHICS_UICONTAINER_HPP

#include <list>
#include <memory>
#include <PicoGameEngine/Core/Config.hpp>

namespace pge
{
    class UiElement;

    class PGE_API UiContainer
    {
    public:
        UiContainer() = default;

        UiContainer(const UiContainer & ) = delete;

        UiContainer(UiContainer && ) = delete;

        UiContainer & operator=(const UiContainer & ) = delete;

        UiContainer & operator=(UiContainer && ) = delete;

        virtual ~UiContainer() = default;

        //void add(std::unique_ptr<UiElement> element);

    private:
        //std::list<std::unique_ptr<UiElement>> elements_;
    
    };
}

#endif
