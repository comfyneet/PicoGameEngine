#ifndef HELLOGAME_HPP
#define HELLOGAME_HPP

#include <PicoGameEngine/PicoGameEngine.hpp>

class HelloGame : public pge::Game
{
public:
    HelloGame();

    void init() override;

    void draw() override;
};

#endif
