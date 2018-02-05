#ifndef HELLOGAME_HPP
#define HELLOGAME_HPP

#include <PicoGameEngine/PicoGameEngine.hpp>

class HelloGame : public pge::Game
{
public:
    void init() override;
};

#endif
