#include <PicoGameEngine/PicoGameEngine.hpp>
#include "HelloGame.hpp"

int main()
{
    const HelloGame hello_game{};

    pge::Application app(hello_game);
    app.start();

    return 0;
}
