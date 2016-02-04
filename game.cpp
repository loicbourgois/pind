#include "game.hpp"

#include <thread>

#define WAIT 100

Game::Game()
{

}

Game::Game(std::string mapPath)
{
    map = Map(this, mapPath);
}

void Game::start()
{
    while(true)
    {
        display();
        std::this_thread::sleep_for(std::chrono::milliseconds(WAIT));
    }
}

void Game::display()
{
    std::cout << std::string( 100, '\n' );
    std::cout << map.toString();
}
