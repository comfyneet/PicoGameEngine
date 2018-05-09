#include "HelloGame.hpp"
#include <memory>

HelloGame::HelloGame()
{
    gui_ = std::make_unique<pge::Gui>(pge::Vector2U(1024, 768));
}

void HelloGame::init()
{
    auto hello_text = std::make_unique<pge::Text>("Hello World", 24);
    auto secondary_text = std::make_unique<pge::Text>("comfyneet", 12);

    gui_->add_element(std::move(hello_text));
    gui_->add_element(std::move(secondary_text));
}

void HelloGame::draw()
{
    gui_->draw();
}
